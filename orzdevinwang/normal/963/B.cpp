#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long 
using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 9;
int n, fa[N], dfn[N], deg[N], mp[N], idt;
vi e[N];
bool vis[N];
void dfs(int x, int f) {
	mp[++idt] = x, dfn[x] = idt;
	for(const int &v : e[x]) if(v != f) dfs(v, x);
}
int ns[N];
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) {
		cin >> fa[i];
		if(fa[i]) e[fa[i]].emplace_back(i), e[i].emplace_back(fa[i]), deg[i] += 1, deg[fa[i]] += 1;
	}
	dfs(1, 0);
	priority_queue < int > q;
	L(i, 1, n) if(!(deg[i] & 1)) q.push(dfn[i]); 
	int cnt = 0;
	while(!q.empty()) {
		int u = mp[q.top()];
		q.pop();
		if((deg[u] & 1) || vis[u]) continue ;
		ns[++cnt] = u, vis[u] = true;
		for(const int &v : e[u]) {
			deg[v] -= 1;
			if(!(deg[v] & 1)) q.push(dfn[v]);
		}
	}
	if(cnt != n) {
		cout << "NO" << '\n';
	} else {
		cout << "YES\n";
		L(i, 1, cnt) cout << ns[i] << '\n';
	}
	return 0;
}