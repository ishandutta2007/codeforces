#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); i++) 
#define R(i, j, k) for(int i = (j); i >= (k); i--)
#define ll long long
#define sz(a) ((int) a.size())
#define vi vector<int>
using namespace std;
const int N = 7, M = 15625 + 5, inf = 1e9;
int n, m, a[N], b[N], c[N][N], dp[2][M], all[M], pw[N], cnt = 0;
void cmin(int &x, int y) { if(x > y) x = y; }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	pw[0] = 1;
	L(i, 1, m) pw[i] = pw[i - 1] * 5;
	L(i, 0, pw[m] - 1) all[i] = all[i / 5] + i % 5;
	
	L(i, 1, n) cin >> a[i], cnt += a[i];
	L(i, 1, m) cin >> b[i], cnt -= b[i];
	if(cnt > 0) return cout << "-1\n", 0;
	L(i, 1, n) L(j, 1, m) cin >> c[i][j];
	memset(dp, 0x3f, sizeof(dp));
	int o = 0, sum = 0;
	dp[0][0] = 0;
	L(i, 1, n) {
		sum += a[i];
		L(t, 1, m) {
			o ^= 1, memset(dp[o], 0x3f, sizeof(dp[o]));
			L(j, 0, pw[m] - 1) if(dp[o ^ 1][j] < inf) {
				int w = j / pw[t - 1] % 5;
				cmin(dp[o][j], dp[o ^ 1][j]);
				L(k, 1, b[t] - w) cmin(dp[o][j + k * pw[t - 1]], dp[o ^ 1][j] + c[i][t]);
			}
		}
		L(j, 0, pw[m] - 1) if(all[j] != sum) dp[o][j] = inf;
	}
	int ns = 1e9;
	L(i, 0, pw[m] - 1) ns = min(ns, dp[o][i]); //, cout << i << ": " << dp[o][i] << "\n";
	cout << ns << "\n";
	return 0;
}