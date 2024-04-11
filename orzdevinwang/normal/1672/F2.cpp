#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
#define ld long double
#define i128 __int128 
using namespace std;
const int N = 1e6 + 7;
int n, m, c[N], a[N], b[N];
vi qwq[N];
vi e[N];
bool vis[N];
int dfn[N], low[N], idt;
int stk[N], tp;
bool ok = false;
void dfs(int x) {
//	cout << x << endl;
	dfn[x] = low[x] = ++idt, stk[++tp] = x, vis[x] = 1;
	for(const int &v : e[x]) {
		if(!dfn[v]) dfs(v), low[x] = min(low[x], low[v]);
		else if(vis[v]) low[x] = min(low[x], dfn[v]);
	}
//	cout << x << " : " << dfn[x] << ' ' << low[x] << endl;
	if(dfn[x] == low[x]) {
		if(stk[tp] != x) 
			ok = true;
		for(int u = 0; u != x; ) 
			u = stk[tp], vis[u] = 0, --tp;
	}
	
}
void Main () {
	cin >> n;
	L(i, 1, n) c[i] = 0, dfn[i] = low[i] = 0, e[i].clear();
	idt = 0;
	L(i, 1, n) cin >> a[i], c[a[i]] += 1;
	L(i, 1, n) cin >> b[i];
	int np = 0;
	L(i, 1, n) 
		if(c[i] > c[np]) 
			np = i;
	ok = 0;
	L(i, 1, n) 
		if(a[i] != np && b[i] != np){
			if(a[i] == b[i]) 
				ok = 1;
			e[a[i]].emplace_back(b[i]);
		}
	L(i, 1, n) if(!dfn[i]) dfs(i);
	if(!ok) cout << "AC\n";
	else cout << "WA\n";
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}