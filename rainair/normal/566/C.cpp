#include<bits/stdc++.h>

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

const int MAXN = 2e5 + 5;

struct Edge{
	int to,w,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;

inline void add(int u,int v,int w){
	e[++cnt] = (Edge){v,w,head[u]};head[u] = cnt;
	e[++cnt] = (Edge){u,w,head[v]};head[v] = cnt;
}

int mx[MAXN],sz[MAXN],rt;
bool vis[MAXN];

inline void getroot(int v,int fa=0){
	mx[v] = 0;sz[v] = 1;
	for(int i = head[v];i;i = e[i].nxt){
		if(e[i].to == fa || vis[e[i].to]) continue;
		getroot(e[i].to,v);sz[v] += sz[e[i].to];
		mx[v] = std::max(mx[v],sz[e[i].to]);
	}
	mx[v] = std::max(mx[v],mx[0]-sz[v]);
	if(mx[rt] > mx[v]) rt = v;
}

double sd[MAXN],smd;
int d[MAXN],now;

inline void getdep(int v,LL dep,int fa=0){
	double d = 1.0*::d[v]*std::sqrt(1.0*dep)*3.0/2.0;
	sd[now] += d;smd += d;
	for(int i = head[v];i;i = e[i].nxt){
		if(e[i].to == fa) continue;
		getdep(e[i].to,dep+e[i].w,v);
	}
}

inline double getans(int v,LL dep=0,int fa=0){
	double res = 1.0*dep*sqrt(1.0*dep)*d[v];
	for(int i = head[v];i;i = e[i].nxt){
		if(e[i].to == fa) continue;
		res += getans(e[i].to,dep+e[i].w,v);
	}
	return res;
}

int t1=-1,t2=-1;
int ans1;double ans2=1e20;
inline void work(int v){
	vis[v] = 1;smd = 0;
	for(int i = head[v];i;i = e[i].nxt){
		if(vis[e[i].to]) continue;
		now = e[i].to;sd[now] = 0;
		getdep(e[i].to,e[i].w,v);
	}
	double sm = getans(v);
	if(sm < ans2){
		ans2 = sm;ans1 = v;
	}
	for(int i = head[v];i;i = e[i].nxt){
		if(vis[e[i].to]) continue;
		if(smd-sd[e[i].to]-sd[e[i].to] < 0){
			mx[rt = 0] = sz[e[i].to];getroot(e[i].to);
			t1 = v;t2 = e[i].to;work(rt);return;
		}
	}
}

int main(){
	int n;scanf("%d",&n);
	FOR(i,1,n) scanf("%d",d+i);
	FOR(i,2,n){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	mx[rt = 0] = n;getroot(1);t1 = rt;
	work(rt);
	printf("%d %.10lf\n",ans1,ans2);
	return 0;
	if(t2 == -1){
		printf("%d %.10lf\n",t1,getans(t1));return 0;
	}
	double ans1 = getans(t1),ans2 = getans(t2);
	if(ans1 < ans2) printf("%d %.10lf\n",t1,ans1);
	else printf("%d %.10lf\n",t2,ans2);
	return 0;
}