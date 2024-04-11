#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

const int N = 300005;
int n, ans, a[N], f[N], g[N];
vector<int> e[N];
void dfs(int u){
	if(!e[u].size()) g[u]=1, ++ans;
	else if(a[u]) g[u]=n;
	for(int v:e[u]){
		dfs(v);
		if(a[u]) g[u]=min(g[u], g[v]);
		else g[u]+=g[v];
	}
}
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=2; i<=n; ++i) scanf("%d", f+i), e[f[i]].push_back(i);
	dfs(1);
	return printf("%d", ans-g[1]+1), 0;
}