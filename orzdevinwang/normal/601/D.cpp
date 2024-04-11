#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 1 << 20;
int n, c[N], rt[N], all, mx, ns;
int ch[N][26], dp[N], tot;
int merge (int x, int y) {
	if(!x || !y) return x | y;
	dp[x] = 1;
	L(i, 0, 25) 
		ch[x][i] = merge (ch[x][i], ch[y][i]), dp[x] += dp[ch[x][i]];
	return x;
}
char s[N];
vi e[N];
void dfs (int x, int fa) {
	for (const int &v : e[x]) if(v != fa) dfs (v, x), ch[x][s[v] - 'a'] = merge (ch[x][s[v] - 'a'], v);
	dp[x] = 1;
	L(i, 0, 25) dp[x] += dp[ch[x][i]];
	int W = dp[x] + c[x];
	if(W > mx) mx = W, ns = 1;
	else if(W == mx) ns += 1;
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n;
	L(i, 1, n) cin >> c[i];
	cin >> (s + 1);
	L(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs (1, 0);
	cout << mx << '\n' << ns << '\n';
	return 0;
}