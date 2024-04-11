#include <bits/stdc++.h>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
typedef vector<int> vi;

const int N=1e5+50;
const int M=1e5+50;
const int P=10;

int n;
ll ans;
int head[N],nxt[N<<1],to[N<<1],cost[N<<1],tot;
void add_edge(int u,int v,int c) {
	nxt[++tot]=head[u]; head[u]=tot; to[tot]=v; cost[tot]=c;
}

ll inv[N],pw[N];
map<ll,int> mmap;
int root,mod;
int son[N],siz[N],mx[N];
bool vis[N];

void ext_gcd(ll a,ll b,ll &d,ll &x,ll &y) {
    if (!b) {d=a; x=1; y=0;}
    else {ext_gcd(b,a%b,d,y,x); y-=x*(a/b);}
}
void pre() {
	pw[0]=1;
	rep(i,1,N) pw[i]=pw[i-1]*P%mod;
	rep(i,0,N) {
		ll a=pw[i],b=mod;
		ll d,x,y;
		ext_gcd(a,b,d,x,y);
		x=(x%mod+mod)%mod;
		inv[i]=x;
	}
}

void getroot(int u,int f,int tot) {
	siz[u]=1; mx[u]=0;
	for (int i=head[u];i;i=nxt[i]) {
		int v=to[i];
		if (v==f||vis[v]) continue;
		getroot(v,u,tot);
		siz[u]+=siz[v];
		if (siz[v]>mx[u]) mx[u]=siz[v];
		mx[u]=max(siz[v],mx[u]);
	}
	if (mx[u]<tot-siz[u]) mx[u]=tot-siz[u];
	if (mx[u]<mx[root]) root=u;
}
void calc(int u,int f,ll res,int len) {
	if (!res) ans++;
	if (mmap.count(res)) ans+=mmap[res];
	for (int i=head[u];i;i=nxt[i]) {
		int v=to[i],c=cost[i];
		if (vis[v]||v==f) continue;
		calc(v,u,(c*pw[len]%mod+res)%mod,len+1);
	}
}
void add(int u,int f,ll res,int op,int len) {
	ll tmp=(mod-res)*inv[len]%mod;
	mmap[tmp]+=op;
	for (int i=head[u];i;i=nxt[i]) {
		int v=to[i],c=cost[i];
		if (vis[v]||v==f) continue;
		add(v,u,(res*P%mod+c)%mod,op,len+1);
	}
}
void solve(int u=1,int tot=n) {
	root=0; getroot(u,0,tot);
	vis[root]=1;
	mmap.clear();
	for (int i=head[root];i;i=nxt[i]) {
		int v=to[i],c=cost[i];
		if (vis[v]) continue;
		add(v,root,c,1,1);
	}
	if (mmap.count(0)) ans+=mmap[0];
	for (int i=head[root];i;i=nxt[i]) {
		int v=to[i],c=cost[i];
		if (vis[v]) continue;
		add(v,root,c,-1,1);
		calc(v,root,c,1);
		add(v,root,c,+1,1);
	}
	int sz=siz[root]; // root
	for (int i=head[root];i;i=nxt[i]) {
		int v=to[i];
		if (vis[v]) continue;
		solve(v,siz[v]>sz?tot-sz:siz[v]);
	}
}

int main() {
	scanf("%d%d",&n,&mod);
	mx[0]=inf;
	pre();
	rep(i,1,n) {
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		u++,v++; c%=mod;
		add_edge(u,v,c);
		add_edge(v,u,c);
	}
	solve(1,n);
	printf("%lld\n",ans);
	return 0;	
}