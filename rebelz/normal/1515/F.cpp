#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,x,tot;
int v[600005],c[600005],nxt[600005],h[300005],f[300005];
ll a[300005];
vector<pii> adj[300005];
set<pll> st;
bool vis[300005];

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

void addedge(int x,int y,int z){
	v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=z; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u){
	for(int p=h[u];p;p=nxt[p]){
		if(vis[v[p]]) continue;
		adj[u].pb(mp(v[p],c[p]));
		adj[v[p]].pb(mp(u,c[p]));
		vis[v[p]]=1;
		dfs(v[p]);
	}
}

int main(){
	n=readint(); m=readint(); x=readint();
	ll sum=0;
	for(int i=1;i<=n;i++) a[i]=readint(),sum+=a[i];
	if(sum<1ll*x*(n-1)) return printf("NO\n"),0;
	printf("YES\n");
	for(int i=1;i<=m;i++) addedge(readint(),readint(),i);
	vis[1]=1; dfs(1);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=n;i++) st.insert(mp(a[i],i));
	for(int i=1;i<n;i++){
		auto it=--st.end();
		int u=it->se,v=0;
		while(getf(adj[u].back().fi)==u) adj[u].pop_back();
		v=getf(adj[u].back().fi);
		printf("%d\n",adj[u].back().se);
		st.erase(mp(a[u],u));
		st.erase(mp(a[v],v));
		if(adj[u].size()>adj[v].size()) swap(u,v);
		f[u]=v;
		for(auto r:adj[u]) adj[v].pb(r);
		a[v]=a[v]+a[u]-x;
		assert(a[v]>=0);
		st.insert(mp(a[v],v));
	}
	return 0;
}