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
#define P std::pair<int,int> // p,e
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 10000+5;
const int MAXM = 700;
const int ha = 1e9 + 7;
const int BASE = 701;

bool p[MAXN];
int prime[MAXN],tot;

struct Node{
	int e[MAXM],dp;
	Node(){CLR(e,0);dp = -1;}

	inline int hsh(){
		int res = 1;
		FOR(i,0,MAXM-1) res = (1ll*res*BASE%ha+e[i])%ha;
		return res;
	}

	inline int dep(){
		if(dp != -1) return dp;
		int res = 0;
		FOR(i,0,MAXM-1) res += e[i];
		dp = res;
		return res;
	}

	inline bool operator == (const Node &t) const {
		FOR(i,0,MAXM-1) if(e[i] != t.e[i]) return false;
		return true;
	}

	inline bool operator != (const Node &t) const {
		FOR(i,0,MAXM-1) if(e[i] != t.e[i]) return true;
		return false;
	}

	inline void print(){
		FOR(i,1,5) printf("%d ",e[i]);puts("");
	}
}a[MAXN<<2];int N;
std::map<int,int> S;

inline Node lca(const Node &a,const Node &b){
	Node res;
	ROF(i,MAXM-1,0){
		res.e[i] = std::min(a.e[i],b.e[i]);
		if(a.e[i] != b.e[i]) break;
	}
	return res;
}

struct Edge{
	int to,w,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;

inline void add(int u,int v,int w){
	w = std::abs(w);
	e[++cnt] = (Edge){v,w,head[u]};head[u] = cnt;
	e[++cnt] = (Edge){u,w,head[v]};head[v] = cnt;
}

inline void work(int x){
	++N;
	FOR(i,1,tot){
		if(prime[i] > x) break;
		int q = prime[i];
		while(q <= x){
			a[N].e[i] += x/q;
			q = q*prime[i];
		}
	}
}

inline void prework(){
	FOR(i,2,MAXN-1){
		if(!p[i]) prime[++tot] = i;
		for(int j = 1;j <= tot && i*prime[j] < MAXN;++j){
			p[i*prime[j]] = 1;
			if(!(i%prime[j])) break;
		}
	}
	FOR(i,1,5000) work(i);
}
int RT;
int stk[MAXN],tp;
inline void build(){
	RT = 1;stk[tp = 1] = RT;
	FOR(i,1,N) S[a[i].hsh()] = i;
	FOR(i,2,5000){
		Node l = lca(a[stk[tp]],a[i]);int v = S[l.hsh()];
		if(!v) v = S[l.hsh()] = ++N,a[N] = l;
		if(v == stk[tp]){
			stk[++tp] = i;
			continue;
		}
		while(tp >= 2 && a[stk[tp-1]].dep() >= a[v].dep()){
			add(stk[tp],stk[tp-1],a[stk[tp]].dep()-a[stk[tp-1]].dep());
			tp--;
		}
		if(stk[tp] != v){
			add(v,stk[tp],a[v].dep()-a[stk[tp]].dep());
			stk[tp] = v;
		}
		stk[++tp] = i;
	}
	ROF(i,tp,2) add(stk[i-1],stk[i],a[stk[i]].dep()-a[stk[i-1]].dep());
}

int sz[MAXN],val[MAXN];
LL now;
inline void dfs(int v,int sm=0,int fa=0){
	sz[v] = val[v];now += 1ll*sm*val[v];
	// if(v == 9319) DEBUG(v);
	for(int i = head[v];i;i = e[i].nxt){
		if(e[i].to == fa) continue;
		dfs(e[i].to,sm+e[i].w,v);
		sz[v] += sz[e[i].to];
	}
}
int n;
LL ans;

inline void find(int v,int fa=0){
	ans = std::min(ans,now);
	for(int i = head[v];i;i = e[i].nxt){
		if(e[i].to == fa) continue;
		LL t = now;
		now += 1ll*e[i].w*(n-2*sz[e[i].to]);
		find(e[i].to,v);
		now = t;
	}
}

int main(){
	// DEBUG(1);
	prework();
	build();//DEBUG(N);
	// a[3].print();a[4].print();
	// lca(a[4],a[3]).print();
	scanf("%d",&n);
	FOR(i,1,n){
		int x;scanf("%d",&x);val[std::max(1,x)]++;
	}
	// DEBUG(a[9316].dep());
	dfs(RT);//DEBUG(RT);
	ans = now;
	find(RT);
	printf("%lld\n",ans);
	return 0;
}