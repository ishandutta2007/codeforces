#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define fi first
#define se second
using namespace std;
const int N = 30; 
const int M = 9;
int det[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m, cnt, val[N], stx, sty, ans, dp[N][N][1 << M];
pii baoz[N];
char s[N][N];
bool rm(int t, int x, int y) { return x == baoz[t].fi && y > baoz[t].se; }
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	L(i, 1, n) cin >> s[i] + 1;
	L(i, 1, n) L(j, 1, m) if(s[i][j] == 'S') stx = i, sty = j;
	L(i, 1, n) L(j, 1, m) if(s[i][j] >= '0' && s[i][j] <= '9') ++cnt, baoz[s[i][j] - '0'] = mkp(i, j);
	L(i, 1, cnt) cin >> val[i];
	L(i, 1, n) L(j, 1, m) if(s[i][j] == 'B') baoz[++cnt] = mkp(i, j), val[cnt] = -1e5;
	memset(dp, 0x3f, sizeof(dp));
	queue< pair<pii, int> > q;
	dp[stx][sty][0] = 0, q.push(mkp(mkp(stx, sty), 0));
	while(!q.empty()) {
		int fx = q.front().fi.fi, fy = q.front().fi.se, mask = q.front().se;
		q.pop();
		L(i, 0, 3) {
			int gx = fx + det[i][0], gy = fy + det[i][1];
			if(gx < 1 || gx > n || gy < 1 || gy > m) continue;
			if(s[gx][gy] != '.' && s[gx][gy] != 'S') continue;
			int nowmask = mask;
			L(g, 1, cnt) if(fx != gx && rm(g, max(fx, gx), gy)) nowmask ^= (1 << (g - 1));
			if(dp[gx][gy][nowmask] <= 1e8) continue;
			dp[gx][gy][nowmask] = dp[fx][fy][mask] + 1;
			q.push(mkp(mkp(gx, gy), nowmask));
		}
	}
	L(i, 0, (1 << cnt) - 1) {
		int sum = - dp[stx][sty][i];
		L(j, 1, cnt) if(i & (1 << (j - 1))) sum += val[j];
		ans = max(ans, sum);
	}
	cout << ans << endl;
	return 0;
}