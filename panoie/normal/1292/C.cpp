#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 3005;
ll ans, g[N][N];
int n, s, siz[N][N], f[N][N];
vector<int> e[N];
vector<pair<int,int>> a[N];
void dfs(int u, int fa=0, int dep=0){
	siz[s][u]=1;
	for(int v:e[u]) if(v!=fa) f[v][s]=u, dfs(v, u, dep+1), siz[s][u]+=siz[s][v];
	a[dep].emplace_back(s, u);
}
int main() {
	scanf("%d", &n);
	for(int i=1, x, y; i<n; ++i)
		scanf("%d%d", &x, &y), e[x].push_back(y), e[y].push_back(x);
	for(int i=1; i<=n; ++i) s=i, dfs(i);
	for(int i=1; i<n; ++i) for(auto &j:a[i])
		ans=max(ans, g[j.first][j.second]=max(g[j.first][f[j.second][j.first]], g[f[j.first][j.second]][j.second])+siz[j.first][j.second]*siz[j.second][j.first]);
	printf("%lld\n", ans);
	return 0;
}