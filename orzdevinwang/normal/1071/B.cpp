#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2007;
int n, m, total, dp[N][N];
char s[N][N];
string f[N], ans;
int G[N][N], tmp[N], tot;
void work() {
	L(i, 0, n) G[n + 1][i] = G[i][n + 1] = G[i][0] = G[0][i] = 1e8;
	G[n][n] = 1;
	L(i, 2, n) {
		tot = 0;
		L(j, 1, i) {
			int wzx = n - j + 1, wzy = n - i + j;
			G[wzx][wzy] = min(G[wzx + 1][wzy], G[wzx][wzy + 1]) + (n + 1) * (s[wzx][wzy] - 'a' + 1);
			tmp[++tot] = G[wzx][wzy];
		}
		sort(tmp + 1, tmp + tot + 1);
		tot = unique(tmp + 1, tmp + tot + 1) - tmp - 1;
		L(j, 1, i) G[n - j + 1][n - i + j] = lower_bound(tmp + 1, tmp + tot + 1, G[n - j + 1][n - i + j]) - tmp;
	}
	R(i, n - 1, 1) {
		tot = 0;
		L(j, 1, i) {
			int wzx = j, wzy = i - j + 1;
			G[wzx][wzy] = min(G[wzx + 1][wzy], G[wzx][wzy + 1]) + (n + 1) * (s[wzx][wzy] - 'a' + 1);
			tmp[++tot] = G[wzx][wzy];
		}
		sort(tmp + 1, tmp + tot + 1);
		tot = unique(tmp + 1, tmp + tot + 1) - tmp - 1;
		L(j, 1, i) G[j][i - j + 1] = lower_bound(tmp + 1, tmp + tot + 1, G[j][i - j + 1]) - tmp;
	}
}
string Find(int x, int y) {
	string res; 
	while(x < n && y < n) {
		if(G[x][y + 1] < G[x + 1][y]) ++y, res.push_back(s[x][y]);
		else ++x, res.push_back(s[x][y]);
	}
	while(x < n) ++x, res.push_back(s[x][y]);
	while(y < n) ++y, res.push_back(s[x][y]);
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin >> n >> m;
	L(i, 1, n) cin >> (s[i] + 1);
	work();
	if(m == 0) return cout << s[1][1] << Find(1, 1) << endl, 0;
	L(i, 1, n) L(j, 1, n) dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + (s[i][j] == 'a');
	int dis = 0;
	L(i, 1, n) L(j, 1, n) if(dp[i][j] + m >= i + j - 1) dis = max(dis, i + j - 1);
	L(i, 1, n) L(j, 1, n) if(i + j - 1 == dis && dp[i][j] + m >= dis) f[++total] = Find(i, j);
	ans = f[1];
	L(i, 2, total) ans = min(ans, f[i]);
	L(i, 1, dis) cout << 'a';
	cout << ans << endl;
	return 0;
} 
// n^2 log rubbish 
// 