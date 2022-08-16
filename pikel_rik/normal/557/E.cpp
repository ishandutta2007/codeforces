#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7, inf = INT_MAX;
const double pi = acos(-1.0);
const int N = 5000 + 5;

int n, k;
string s, ans;
int top, cnt[N * N], tot[N * N], t[N * N][2];
bitset<N> pal[N];

void insert(int j) {
	for (int i = j, cur = 0; i < n; i++) {
		if (!t[cur][s[i] - 'a']) {
			t[cur][s[i] - 'a'] = top++;
		}
		cur = t[cur][s[i] - 'a'];
		cnt[cur] += pal[j][i];
	}
}

void dfs(int x) {
	tot[x] = cnt[x];
	for (int j = 0; j < 2; j++) {
		if (t[x][j]) {
			dfs(t[x][j]);
			tot[x] += tot[t[x][j]];
		}
	}
}

void construct(int x, int k) {
	if (k <= 0) {
		return;
	}
	for (int j = 0; j < 2; j++) {
		if (t[x][j] and tot[t[x][j]] >= k) {
			ans += 'a' + j;
			construct(t[x][j], k - cnt[t[x][j]]);
			return;
		} else if (t[x][j]) {
			k -= tot[t[x][j]];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s >> k;
	n = (int)s.length();

	for (int i = 0; i < n; i++) {
		pal[i][i] = true;
		for (int l = i - 2, r = i + 2; l >= 0 && r < n; l -= 2, r += 2) {
			if (s[l] == s[r]) {
				pal[l][r] = true;
			} else {
				break;
			}
		}
		for (int l = i - 1, r = i + 1; l >= 0 && r < n; l -= 2, r += 2) {
			if (s[l] == s[r]) {
				pal[l][r] = true;
			} else {
				break;
			}
		}

		for (int l = i, r = i + 1; l >= 0 && r < n; l -= 2, r += 2) {
			if (s[l] == s[r]) {
				pal[l][r] = true;
			} else {
				break;
			}
		}

		for (int l = i - 1, r = i + 2; l >= 0 && r < n; l -= 2, r += 2) {
			if (s[l] == s[r]) {
				pal[l][r] = true;
			} else {
				break;
			}
		}
	}

	top = 1;
	for (int i = 0; i < n; i++) {
		insert(i);
	}

	dfs(0);
	construct(0, k);
	cout << ans << '\n';
	return 0;
}