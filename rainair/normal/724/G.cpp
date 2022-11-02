#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
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

const int MAXN = 2e5 + 5;
const int ha = 1e9 + 7;
const int inv2 = 500000004;

struct Edge{
	int to;LL w;int nxt;
}e[MAXN<<1];
int head[MAXN],cnt;

inline void add(int u,int v,LL w){
	e[++cnt] = (Edge){v,w,head[u]};head[u] = cnt;
	e[++cnt] = (Edge){u,w,head[v]};head[v] = cnt;
}

int n,m;
bool vis[MAXN];
LL ans = 0;

LL dis[MAXN];
const int MAXM = 63;
LL b[MAXM+1];

inline void insert(LL x){
	ROF(i,MAXM,0){
		if((x>>i)&1){
			if(!b[i]){b[i] = x;break;}
			else x ^= b[i];
		}
	}
}

bool ins[MAXN];
std::vector<LL> S;

inline void dfs(int v,int fa=0){
	ins[v] = vis[v] = 1;S.pb(dis[v]);
	for(int i = head[v];i;i = e[i].nxt){
		if(e[i].to == fa) continue;
		if(!vis[e[i].to]){
			dis[e[i].to] = dis[v]^e[i].w;
			dfs(e[i].to,v);
		}
		else if(ins[e[i].to]){
			insert(dis[v]^dis[e[i].to]^e[i].w);
		}
	}
	ins[v] = 0;
}

inline void work(int x){
	S.clear();CLR(b,0);dfs(x);
	int sz = 0;FOR(i,0,MAXM) if(b[i]) ++sz;
	int pw = (1ll<<sz)%ha,pw1 = (1ll<<(std::max(0,sz-1)))%ha;
	int n = S.size();
	FOR(i,0,MAXM){
		int gx = (1ll<<i)%ha;
		bool flag = 0;
		FOR(j,0,MAXM) if((b[j]>>i)&1) {flag = 1;break;}
		if(flag){
			gx = 1ll*gx*n%ha*(n-1)%ha*inv2%ha*pw1%ha;
		}
		else{
			int t = 0;
			for(auto x:S) if((x>>i)&1) ++t;
			gx = 1ll*gx*t%ha*(n-t)%ha*pw%ha;
		}
		(ans += gx) %= ha;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,m){
		int u,v;LL w;scanf("%d%d%lld",&u,&v,&w);
		add(u,v,w);
	}
	FOR(i,1,n) if(!vis[i]) work(i);
	printf("%lld\n",ans);
	return 0;
}