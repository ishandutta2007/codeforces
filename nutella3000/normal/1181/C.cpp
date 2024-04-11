#include <bits/stdc++.h>
 
using namespace std;
 
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
//#define GCC optimize("O3, Ofast")
//#define GCC optimize("unroll-loops")
#define aidar asadulin
  
#define int long long
#define ull long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld double
 
const int inf = 1e9 + 7;
const int max_n = 1001;

int n, m;
string s[max_n];
int dp[max_n][max_n], p[max_n][max_n];

void solve() {
	cin >> n >> m;
	for(int i = 0;i < n;i++)
		cin >> s[i];
	for(int i = n - 1;i >= 0;i--) {
		for(int j = m - 1;j >= 0;j--) {
			dp[i][j] = 1;
			p[i][j] = i;
			if (j != m - 1 && s[i][j] == s[i][j + 1]) dp[i][j] = dp[i][j + 1] + 1;
			if (i != n - 1 && s[i][j] == s[i + 1][j]) {
				//chkmin(dp[i][j], dp[i + 1][j]);
				p[i][j] = p[i + 1][j];
			}
		}
	}
	int res = 0;
	for(int i1 = 0;i1 < n;i1++) {
		for(int j = 0;j < m;j++) {
			int i2 = p[i1][j] + 1;
			if (i2 == n) continue;
			int i3 = p[i2][j] + 1;
			if (i3 == n || i2 - i1 != i3 - i2 || p[i3][j] + 1 - i3 < i2 - i1) continue;
			int num = inf;
			for(int i = i1;i < i2 - i1 + i3;i++)
				chkmin(num, dp[i][j]);
			res += num;
		}
	}
	cout << res;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}