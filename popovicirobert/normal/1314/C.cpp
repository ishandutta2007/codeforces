#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))

using namespace std;

const ll INF = 1000000000000000005;
const int MAXN = 1005;

char aux[2 * MAXN + 1];
int z[2 * MAXN + 1];

inline void make_Z(int sz) {
	fill(z, z + sz + 1, 0);
	int pos = 0;
	z[1] = sz;
	for(int i = 2; i <= sz; i++) {
		if(pos + z[pos] >= i) {
			z[i] = min(pos + z[pos] - i, z[i - pos + 1]);
		}
		while(i + z[i] <= sz && aux[i + z[i]] == aux[z[i] + 1]) {
			z[i]++;
		}
		if(pos + z[pos] < i + z[i]) {
			pos = i;
		}
	}
}

ll dp[MAXN + 1][MAXN + 1];
ll sp[MAXN + 1][MAXN + 1];

inline ll check(string &str, string &pat, int m) {
	int sz = 0, n = (int)str.size();
	for(auto &it : pat) {
		aux[++sz] = it;
	}
	aux[++sz] = '!';
	int sza = sz;
	for(auto &it : str) {
		aux[++sz] = it;
	}
	make_Z(sz);

	int i, j;
	for(i = 0; i <= n; i++) {
		for(j = 0; j <= m; j++) {
			sp[i][j] = dp[i][j] = 0;
		}
	}

	dp[0][0] = 1;
	for(i = 0; i <= n; i++) {
		for(j = 0; j <= m; j++) {
			if(i > 0) {
				sp[i][j] += sp[i - 1][j];
				sp[i][j] = min(sp[i][j], INF);
			}
			dp[i][j] = min(dp[i][j] + sp[i][j], INF);

			if(dp[i][j] == 0) continue;

			int len = z[i + 1 + sza];
			if(i < n && j < m && len <= n - i) {
				if(len == sza - 1) {
					sp[len + i][j + 1] += dp[i][j];
					sp[len + i][j + 1] = min(sp[len + i][j + 1], INF);
				}
				else if(aux[len + i + 1 + sza] > aux[len + 1]) {
					sp[len + i + 1][j + 1] += dp[i][j];
					sp[len + i + 1][j + 1] = min(sp[len + i + 1][j + 1], INF);
				}
			}
		}
	}
	return dp[n][m];
}

int main() {
#ifdef HOME
	ifstream cin("C.in");
	ofstream cout("C.out");
#endif
	int i, n, m;
	ll k;
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	string str; cin >> n >> m >> k >> str;

	vector <string> all;
	string cur;
	for(i = 0; i < n; i++) {
		cur.clear();
		for(int j = i; j < n; j++) {
			cur.push_back(str[j]);
			all.push_back(cur);
		}
	}
	sort(all.begin(), all.end());
	int res = 0, sz = all.size();
	for(int step = 1 << 19; step; step >>= 1) {
		if(res + step < sz && check(str, all[res + step], m) >= k) {
			res += step;
		}
	}
	cout << all[res];

	return 0;
}