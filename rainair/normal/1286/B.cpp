#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2000+5;

std::vector<int> G[MAXN];
std::vector<int> ans[MAXN];
int n,rt,lim[MAXN],sz[MAXN];

inline void dfs(int v,int fa=0){
	sz[v] = 1;
	for(auto x:G[v]){
		if(x == fa) continue;
		dfs(x,v);sz[v] += sz[x];
		for(auto y:ans[x]) ans[v].pb(y);
	}
	if(lim[v]>sz[v]-1) puts("NO"),exit(0);
	ans[v].insert(ans[v].begin()+lim[v],v);
}
int val[MAXN];
int main(){
	scanf("%d",&n);
	FOR(i,1,n){
		int f;scanf("%d%d",&f,lim+i);
		if(!f) rt = i;
		else G[f].pb(i),G[i].pb(f);
	}
	dfs(rt);int tot = 0;
	for(auto x:ans[rt]) val[x] = ++tot;
	puts("YES");
	FOR(i,1,n) printf("%d ",val[i]);
	puts("");
	return 0;
}