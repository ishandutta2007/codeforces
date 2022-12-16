#include <bits/stdc++.h>

const int MOD = 1E9 + 7;
const int off = 1;

int dp[300][300], ep[300][300][300];
int N; std::string str;
int fail[1500];
int back[1500];
int diff[1500];

int check () {
	int ans = 0;
	for (int i = 0; i < (1 << N + N); ++i) {
		int res = 0, ok = 0;
		for (int j = 0; j < N + N; ++j) {
			if ((i >> j) & 1) --res; else ++res;
			if (res < 0) goto next;
		}
		if (res != 0) goto next;
		for (int j = 0; j + str.size () <= N + N; ++j) {
			for (int k = 0; k < str.size (); ++k)
				if ((str[k] == ')') != ((i >> j + k) & 1)) goto next_try;
			ok = 1; break;
next_try:;
		}
		if (ok) ++ans;
next:;
	}
	return ans;
}

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N; std::cin >> str;
//	srand (time (0));
//	N = rand () % 10 + 1; str.resize (rand () % 10 + 1); for (int i = 0; i < str.size (); ++i) str[i] = rand () % 2 ? '(' : ')';
	int rr = 0, low = 0;
	for (char c : str) rr += (c == '(' ? 1 : -1), low = std::min (rr, low);
	fail[0] = -1;
	for (int i = 1; i < str.size (); ++i) {
		int j = fail[i - 1];
		while (~j && str[j + 1] != str[i]) j = fail[j];
		if (str[j + 1] == str[i]) fail[i] = j + 1;
		else fail[i] = -1;
	}
	back[-1 + off] = -1;
	for (int i = 0; i + 1 < str.size (); ++i) {
		back[i + off] = fail[i];
		while (~back[i + off] && str[back[i + off] + 1] == str[i + 1]) back[i + off] = fail[back[i + off]];
		if (str[back[i + off] + 1] != str[i + 1]) ++back[i + off];
	}
	dp[0][0] = 1;
	for (int i = 0; i < 250; ++i) for (int j = 0; j < 250; ++j) {
		(dp[i + 1][j + 1] += dp[i][j]) %= MOD;
		if (j - 1 >= 0) (dp[i + 1][j - 1] += dp[i][j]) %= MOD;
	}
	ep[0][0][0] = 1;
	for (int i = 0; i < 250; ++i) for (int j = 0; j < 250; ++j) for (int k = -1; k + 1 < str.size (); ++k) {
		if (str[k + 1] == '(') {
			(ep[i + 1][j + 1][off + k + 1] += ep[i][j][off + k]) %= MOD;
			if (j - 1 >= 0) (ep[i + 1][j - 1][off + back[off + k]] += ep[i][j][off + k]) %= MOD;
		} else {
			(ep[i + 1][j + 1][off + back[off + k]] += ep[i][j][off + k]) %= MOD;
			if (j - 1 >= 0) (ep[i + 1][j - 1][off + k + 1] += ep[i][j][off + k]) %= MOD;
		}
	}
	for (int i = 0; i < str.size (); ++i) for (int j = i + 1; j < str.size (); ++j) {
		if (str[j] != str[j - i - 1]) diff[i] = 1;
	}
//	for (int i = 0; i < 10; ++i) for (int j = 0; j < 10; ++j) for (int k = -1; k + 1 < str.size (); ++k) {
//		if (ep[i][j][off + k] > 0) std::cout << i << " " << j << " " << k << " " << ep[i][j][off + k] << "\n";
//	}
	int res = 0;
	if (2 * N >= str.size ()) {
		for (int i = 0; i <= 2 * N - str.size (); ++i)
			for (int j = -low; j < 250 && j + rr < 250; ++j) {
				for (int k = -1; k + 1 < str.size (); ++k) if (k < 0 || diff[k]) 
					(res += 1LL * ep[i][j][off + k] * dp[2 * N - str.size () - i][j + rr] % MOD) %= MOD;
			}
	}
//	std::cout << N << " " << str << "\n";
//	std::cout << res << " " << check () << std::endl;
//	assert (res == check ());
	std::cout << res << "\n";
}