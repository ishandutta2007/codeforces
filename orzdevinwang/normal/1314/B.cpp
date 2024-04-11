#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e6 + 7;
bool vis[N];
int dp[N][2][2];
void build (int o, int L, int R) {
	if (R - L + 1 == 2) {
		int a = vis[L], b = vis[R];
		dp[o][a][b] = dp[o][b][a] = a | b;
		return ;
	}
	int mid = (L + R) >> 1, ls = o << 1, rs = o << 1 | 1;
	build (ls, L, mid), build (rs, mid + 1, R);
	L(a, 0, 1) L(b, 0, 1) L(c, 0, 1) L(d, 0, 1) {
		int cnt = dp[ls][a][b] + dp[rs][c][d] + (a | c) + (b | d);
		L(ab, 0, 1) {
			int x = ab ? a : c, y = ab ? c : a;
			L(cd, 0, 1) {
				int z = cd ? b : d;
				dp[o][x][y] = max(dp[o][x][y], cnt + (y | z));
				dp[o][x][z] = max(dp[o][x][z], cnt + (y | z));
			}
		}
	}
}
int n, k;
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(dp, -0x3f, sizeof(dp));
	cin >> n >> k;
	while (k--) {
		int a;
		cin >> a;
		vis[a] = true;
	}
	build (1, 1, 1 << n);
	cout << max(max(dp[1][0][0], dp[1][0][1] + 1), max(dp[1][1][0] + 1, dp[1][1][1] + 1)) << '\n';
	return 0;
}