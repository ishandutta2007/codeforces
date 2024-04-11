#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 4007;
int n, m, l[N], s[N], c[N];
vi S[N];
ll dp[N][N]; // id; now; 
bool vis[N]; 
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) cin >> l[i];
	R(i, n, 1) S[l[i]].push_back(i);
	L(i, 1, n) cin >> s[i];
	memset(dp, -0x3f, sizeof(dp));
	int d = 0;
	L(i, 1, n) dp[i][0] = 0;
	L(i, 1, n + m) {
		cin >> c[i];
		for (const int &x : S[i]) vis[x] = true;
		R(j, n, 1) {
			if(vis[j]) {
//				cout << "on " << j << '\n';
				R(x, d, 0) dp[j][x + 1] = max(dp[j][x + 1], dp[j][x] - s[j]);
				d += 1; 
			}
			R(x, d, 0) dp[j - 1][x] = max(dp[j - 1][x], dp[j][x]);
		}
		for (const int &x : S[i]) vis[x] = false;
		L(j, 1, n) L(x, 0, d) dp[j][x] += x * c[i];
//		L(j, 1, n) {
//			L(x, 0, d) cout << dp[j][x] << ' ';
//			cout << '\n';
//		}
//		cout << '\n';
		L(j, 1, n) L(x, 1, d) dp[j][x >> 1] = max(dp[j][x >> 1], dp[j][x]), dp[j][x] = -1e18;
//		cout << "after all : \n";
//		L(j, 1, n) {
//			L(x, 0, d) cout << dp[j][x] << ' ';
//			cout << '\n';
//		}
//		cout << '\n';
		d >>= 1;
	}
	cout << dp[1][0] << '\n';
	return 0;
}