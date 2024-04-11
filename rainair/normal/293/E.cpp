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
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;

struct Edge{
	int to,w,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;

inline void add(int u,int v,int w){
	e[++cnt] = (Edge){v,w,head[u]};head[u] = cnt;
	e[++cnt] = (Edge){u,w,head[v]};head[v] = cnt;
}

bool del[MAXN];
int sz[MAXN],mx[MAXN],root,size;

inline void getroot(int v,int fa=0){
	sz[v] = 1;mx[v] = 0;
	for(int i = head[v];i;i = e[i].nxt){
		if(e[i].to == fa || del[e[i].to]) continue;
		getroot(e[i].to,v);
		sz[v] += sz[e[i].to];
		mx[v] = std::max(mx[v],sz[e[i].to]);
	}
	mx[v] = std::max(mx[v],size-sz[v]);
	if(!root || mx[root] > mx[v]) root = v;
}

struct BIT{
	#define lowbit(x) ((x)&(-(x)))
	int tree[MAXN];

	inline void add(int pos,int x){
		pos++;
		while(pos < MAXN){
			tree[pos] += x;
			pos += lowbit(pos);
		}
	}

	inline void clear(int pos){
		pos++;
		while(pos < MAXN){
			tree[pos] = 0;
			pos += lowbit(pos);
		}
	}

	inline int calc(int pos){
		pos++;
		int res = 0;
		while(pos){
			res += tree[pos];
			pos -= lowbit(pos);
		}
		return res;
	}
}bit;

int dis[MAXN],dep[MAXN];
std::vector<P> S;

inline void getdis(int v,int fa=0){
	S.pb(MP(dis[v],dep[v]));
	for(int i = head[v];i;i = e[i].nxt){
		if(e[i].to == fa || del[e[i].to]) continue;
		dep[e[i].to] = dep[v] + 1;
		dis[e[i].to] = dis[v] + e[i].w;
		getdis(e[i].to,v);
	}
}

std::vector<int> opt;
int L,W;

inline LL calc(int v,int val=-1){
	if(val != -1) dis[v] = val,dep[v] = 1;
	else dis[v] = 0,dep[v] = 0;
	S.clear();
	getdis(v);opt.clear();std::sort(all(S));
	// for(auto x:S) printf("%d %d\n",x.fi,x.se);
		// puts("");
	LL ans = 0;
	for(int l = 0,r = (int)S.size()-1;r >= 0;r--){
		while(l < r && S[l].fi+S[r].fi <= W){
			bit.add(S[l].se,1);opt.pb(S[l].se);
			l++;
		}
		while(l && l-1 >= r){
			bit.add(S[--l].se,-1);
		}
		// DEBUG(bit.calc(1));
		if(L-S[r].se >= 0 && l <= r) ans += bit.calc(L-S[r].se);
	}
	// DEBUG(ans);
	for(auto x:opt) bit.clear(x);
	return ans;
}

LL ans = 0;

inline void work(int v){
	ans += calc(v,-1);del[v] = 1;
	for(int i = head[v];i;i = e[i].nxt){
		if(del[e[i].to]) continue;
		ans -= calc(e[i].to,e[i].w);
		root = 0;size = sz[e[i].to];
		getroot(e[i].to);work(root);
	}
}

int n;

int main(){
	scanf("%d%d%d",&n,&L,&W);
	FOR(i,2,n){
		int p,w;scanf("%d%d",&p,&w);
		add(p,i,w);
	}
	root = 0;size = n;getroot(1);
	work(root);
	printf("%lld\n",ans);
	return 0;
}