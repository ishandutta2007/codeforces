#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i) 
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define ll long long 
#define ull unsigned long long 
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a)) 
using namespace std;
const int N = 15, M = N + 1, inf = 1e9;
int n, dp[M][1 << N][M], lst[M][1 << N][M], lsv[M][1 << N][M], sum[1 << N], a[N];
bool vis[N];
inline int get(int x) {
	int cnt = 0;
	L(i, 0, x) cnt += !vis[i];
	return cnt;
} 
void out(int u, int v) {
	cout << get(u) << ' ' << get(v) << '\n', vis[u] = true;
} 
void Main() {
	cin >> n;
	L(i, 0, n - 1) cin >> a[i], vis[i] = false;
	L(i, 0, (1 << n) - 1) sum[i] = 0;
	L(i, 0, n - 1) L(j, 0, (1 << n) - 1) if(j >> i & 1) sum[j] += a[i];
	L(c, 0, n) L(i, 0, (1 << n) - 1) me(dp[c][i], 0x3f);
	dp[0][0][0] = 0;
	L(i, 0, n - 1) {
		L(j, 0, (1 << n) - 1) if(!(j >> i & 1)) {
			int mp = ((1 << n) - 1) ^ j ^ (1 << i), bt = __builtin_popcount(j); 
			for(int cur = mp; ; cur = (cur - 1) & mp) {
				int to = j | (1 << i) | cur, S = sum[cur | (1 << i)];
				L(o, 0, bt) if(dp[i][j][o] < S && S < dp[i][to][o + 1]) 
					dp[i][to][o + 1] = S, lst[i][to][o + 1] = j, lsv[i][to][o + 1] = i;
				if(!cur) break;
			} 
		}
		L(j, 0, (1 << n) - 1) L(o, 0, n) 
			dp[i + 1][j][o] = dp[i][j][o], 
			lst[i + 1][j][o] = lst[i][j][o], 
			lsv[i + 1][j][o] = lsv[i][j][o];
	} 
	R(i, n, 0) if(dp[n][(1 << n) - 1][i] < inf) {
		int x = (1 << n) - 1, y = i, p = n;
		cout << n - i << '\n'; 
		while(x) {
			int msk = x ^ lst[p][x][y], pos = lsv[p][x][y];
			L(j, 0, n - 1) if(j != pos && (msk >> j & 1)) out(j, pos);
			x = lst[p][x][y];
			p = pos - 1;
			y -= 1;	
		}
		return ;
	}
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main(); 
	return 0;
}