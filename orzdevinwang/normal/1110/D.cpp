#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7; 
int n, m, dp[N][5][5], cnt[N];
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	while (n --) {
		int x;
		cin >> x;
		cnt[x] += 1;
	}
	memset(dp, -0x3f, sizeof(dp));
	dp[0][0][0] = 0;
	int ret = 0, ns = 0;
	L(x, 1, m) {
		L(a, 0, 4) L(b, a, 4) {
			int c = min(cnt[x], a), r = cnt[x] - c;
			L(w, 0, min(r, 4)) 
				dp[x][min(b - c, w)][w] = max(dp[x][min(b - c, w)][w], dp[x - 1][a][b] + (r - w) / 3 + c);
		}
		R(a, 4, 1) L(b, a, 4) dp[x][a - 1][b] = max(dp[x][a - 1][b], dp[x][a][b]);
		L(a, 0, 4) R(b, 4, max(a, 1)) dp[x][a][b - 1] = max(dp[x][a][b - 1], dp[x][a][b]);
	}
	L(a, 0, 4) L(b, a, 4) ns = max(ns, dp[m][a][b]);
	cout << ns << "\n";
	return 0;
}