#include <algorithm>
#include <iostream>
#include <iterator>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 100000+5;

struct Edge{
	int to,w,next;
}e[MAXN<<1];

int head[MAXN],cnt,N,size[MAXN],max[MAXN],dist[MAXN],col[MAXN],sum[MAXN],pre[MAXN];
int zx;

inline void add(int u,int v,int w){
	e[++cnt] = (Edge){v,w,head[u]};head[u] = cnt;
}

inline void dfs1(int v,int fa){
	size[v] = 1;
	for(int i = head[v];i;i = e[i].next){
		if(e[i].to == fa) continue;
		dfs1(e[i].to,v);
		size[v] += size[e[i].to];
		max[v] = std::max(max[v],size[e[i].to]);
	}
	max[v] = std::max(max[v],N-size[v]);
	if(max[v] < max[zx]) zx = v;
}

int ans=0;

inline void dfs2(int v){
	ans += dist[v];
	for(int i = head[v];i;i = e[i].next){
		if(e[i].to == pre[v]) continue;
		dist[e[i].to] = dist[pre[e[i].to] = v] + e[i].w;
		dfs2(e[i].to);
	}
}

#define P std::pair<int,int>
#define MP std::make_pair

std::set<int> in[MAXN],min;
std::set<P> S;

inline void find(int x,int root){
	in[col[x]=root].insert(x);
	for(int i = head[x];i;i = e[i].next){
		if(e[i].to == pre[x]) continue;
		find(e[i].to,root);	
	}
}

inline void link(int x,int y){
	int fx = col[x],fy = col[y];
	min.erase(y);
	if(fx){
		S.erase(MP(sum[fx],fx));
		S.insert(MP(--sum[fx],fx));
	}
	if(fy){
		in[fy].erase(y);
		if(!in[fy].empty()) min.insert(*in[fy].begin());
		S.erase(MP(sum[fy],fy));
		S.insert(MP(--sum[fy],fy));
	}
}

inline int solve(int x){
	int ans;
	if(S.rbegin()->first == N-x+1 && S.rbegin()->second != col[x]){
		ans = *in[S.rbegin()->second].begin();
	}
	else{
		ans = (col[*min.begin()] != col[x] || x == zx) ? *min.begin() : *std::next(min.begin());
	}
	link(x,ans);
	return ans;
}

signed main(){
	scanf("%I64d",&N);max[zx] = LLONG_MAX;
	FOR(i,1,N-1){
		int u,v,w;scanf("%I64d%I64d%I64d",&u,&v,&w);
		add(u,v,w);add(v,u,w);
	}
	dfs1(1,0);dfs2(zx);
//00	FOR(i,1,N) printf("%d ",max[i]);puts("");
	printf("%I64d\n",ans*2ll);
	if(N == 1) {puts("1");return 0;}
	min.insert(zx);
	for(int i = head[zx];i;i = e[i].next){
		find(e[i].to,e[i].to);
		min.insert(*in[e[i].to].begin());
		S.insert(MP(sum[e[i].to] = in[e[i].to].size()*2,e[i].to));
	}
	FOR(i,1,N) printf("%I64d ",solve(i));
	puts("");
	return 0;
}