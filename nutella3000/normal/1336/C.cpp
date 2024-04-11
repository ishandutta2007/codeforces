#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
  
using namespace std;
const int inf = 2e9 + 7;
const int max_n = 3001;
const int mod = 998244353;
string s, a;
int f[max_n][max_n];

void solve() {
	cin >> s >> a;

	int n = s.size(), m = a.size();

	f[n][0] = 1;

	for(int i = n - 1;i >= 0;i--) {
		for(int j = 0;j <= m && (n - i) >= j;j++) {
			if (i + j >= m || a[i + j] == s[i]) f[i][j] += f[i + 1][j];

			if (j == 0 && i >= m) {
				f[i][j]++;
				continue;
			}

			if (j == m) f[i][j] += f[i + 1][j];

			if (a[j - 1] == s[i]) f[i][j] += f[i + 1][j - 1];

			f[i][j] %= mod;
			//cout << i << " " << j << " " << f[i][j] << '\n';
		}
	}

	int res = 0;
	for(int i = 0;i <= m;i++) res += f[0][i];

	cout << res % mod;
}



signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
   	ios_base::sync_with_stdio(0);

   	solve();
}