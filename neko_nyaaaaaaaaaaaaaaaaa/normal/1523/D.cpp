#include <bits/stdc++.h>
using namespace std;

#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int RAND(int lo, int hi) {
	return uniform_int_distribution<int>(lo, hi)(rng);
}

string tryit(int n, int m, int p, vector<string> &f, int id) {
	vector<int> ids;
	for (int i = 0; i < m; i++) {
		if (f[id][i] == '1') {
			ids.push_back(i);
		}
	}
	int b = ids.size();

	vector<int> dp(1 << b);
	for (int i = 0; i < n; i++) {
		int msk = 0;
		for (int j = 0; j < b; j++) {
			if (f[i][ids[j]] == '1') {
				msk |= (1 << j);
			}
		}
		dp[msk]++;
	}

	for (int j = 0; j < b; j++) {
		for (int i = 0; i < (1 << b); i++) {
			if ((i & (1 << j)) == 0) dp[i] += dp[i ^ (1 << j)];
		}
	}

	int ans = 0;
	for (int i = 0; i < (1 << b); i++) {
		if (dp[i] >= (n+1)/2) {
			if (__builtin_popcount(i) > __builtin_popcount(ans)) ans = i;
		}
	}

	string s(m, '0');
	for (int i = 0; i < b; i++) {
		if (ans & (1 << i)) s[ids[i]] = '1';
	}
	return s;
}

int cck(string &s) {
	int cnt = 0;
	for (char c: s) cnt += (c == '1');
	return cnt;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, m, p; cin >> n >> m >> p;
	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	// pick a random friend
	// go through all their subsets
	// see how many likes it
	// do sos dp 
	// O(N) + O(2^15)
	string ans(m, '0');
	int ik = -1;
	for (int ite = 0; ite <= 40; ite++) {
		int gf = RAND(0, n-1);

		string cl = tryit(n, m, p, s, gf);
		if (cck(cl) > cck(ans)) {
			ans = cl; ik = gf;
		}
	}
	cout << ans << '\n';

	return 0;
}