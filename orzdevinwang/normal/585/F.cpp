#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1e5 + 7, M = 55, mod = 1e9 + 7;
int n, d;
char s[N], l[N], r[N];
int ch[N][10], fa[N], tot = 1;
bool vis[N];
void bfs() {
	queue < int > q;
	L(i, 0, 9) 
		if(ch[1][i]) q.push(ch[1][i]), fa[ch[1][i]] = 1; 
		else ch[1][i] = 1;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		L(i, 0, 9) {
			int v = ch[u][i];
			if(v) fa[v] = ch[fa[u]][i], q.push(v);
			else ch[u][i] = ch[fa[u]][i];
		}
	}
}
int dp[M][N][2][2];
int DP (int k, int x, bool ox, bool oy) {
	if (vis[x]) return 0;
	if (k == d + 1) return 1;
	if (dp[k][x][ox][oy] != -1) return dp[k][x][ox][oy];
	int ret = 0;
	L(i, ox ? l[k] - '0' : 0, oy ? r[k] - '0' : 9) 
		(ret += DP(k + 1, ch[x][i], ox & (i == l[k] - '0'), oy & (i == r[k] - '0'))) %= mod;
	return dp[k][x][ox][oy] = ret; 
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> (s + 1) >> (l + 1) >> (r + 1), n = strlen(s + 1), d = strlen(l + 1);
	int all = 0;
	L(i, 1, d) 
		all = (ll) all * 10 % mod, (all += r[i] - l[i]) %= mod;
	int hd = d / 2;
	L(i, 1, n - hd + 1) {
		int now = 1;
		L(j, i, i + hd - 1) {
			if(!ch[now][s[j] - '0']) ch[now][s[j] - '0'] = ++tot;
			now = ch[now][s[j] - '0'];
		}
		vis[now] = true;
	}
	bfs ();
	(all += 1) %= mod;
	memset(dp, -1, sizeof(dp));
	cout << (all + mod - DP (1, 1, true, true)) % mod << '\n';
	return 0;
}
/*

999
998
999

*/