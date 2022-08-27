#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e3 + 7, M = N * N / 2;
const ll linf = 1e18;
int n, m, ch[M][26], tot = 1;
ll k, dp[N][N], DP[N][N];
vector < pair < int, int > > vc[M];
char s[N];
int gl[M], gr[M], tp;
void dfs (int x) {
	for (auto w : vc[x]) ++tp, gl[tp] = w.first, gr[tp] = w.second;
	L(i, 0, 25) if(ch[x][i]) dfs (ch[x][i]);
}
int vr[N];
void check(int x) {
	L(i, 1, n) vr[i] = n + 2;
	L(i, x, tp) vr[gl[i]] = min(vr[gl[i]], gr[i] + 1);
	memset(dp, 0, sizeof(dp));
	memset(DP, 0, sizeof(DP));
	dp[n + 1][0] = DP[n + 1][0] = 1;
	R(i, n, 1) {
		L(k, 1, m) dp[i][k] = DP[vr[i]][k - 1];
		L(k, 0, m) DP[i][k] = DP[i + 1][k] + dp[i][k], DP[i][k] = min(DP[i][k], linf);
	}
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k >> (s + 1);
	L(i, 1, n) {
		int now = 1;
		L(j, i, n) {
			int c = s[j] - 'a';
			if(!ch[now][c]) ch[now][c] = ++tot;
			now = ch[now][c], vc[now].push_back({i, j});
		}
	}
	dfs (1);
	check(1);
	int l = 1, r = tp, ns = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		check(mid);
		if(dp[1][m] >= k) ns = mid, l = mid + 1;
		else r = mid - 1;
	}
	if(ns == -1) assert (0);
	L(i, gl[ns], gr[ns]) cout << s[i];
	return 0;
}