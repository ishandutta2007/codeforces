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

int n,ncnt,mcnt,kcnt;
int dfn[300005],dep[300005],a[300005],p[300005],f[300005];
vector<int> adj[300005];

void dfs2(int u){
	sort(adj[u].begin(),adj[u].end(),[&](int x,int y){return a[x]<a[y];});
	for(auto v:adj[u]) dep[v]=dep[u]+1,dfs2(v);
	dfn[u]=++mcnt;
}

int dfs(int u,int t){
	dfn[u]=++ncnt;
	sort(adj[u].begin(),adj[u].end(),[&](int x,int y){return a[x]<a[y];});
	bool fl=0,fl1=0;
	for(auto v:adj[u]){
		dep[v]=dep[u]+1;
		if(a[v]>=t){
			int res=dfs(v,t);
			if(!res) return 0;
			if(fl1&&res==2) return 0;
			fl|=res==2;
			fl1=1;
		}
		else{
			if(fl1) return 0;
			dfs2(v);
			fl=1;
		}
	}
	return 1+fl;
}

void dfs1(int u){
	dfn[u]=++kcnt;
	for(auto v:adj[u]) dfs1(v);
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),p[a[i]]=i;
	int x,y;
	for(int i=1;i<n;i++){
		x=readint(); y=readint();
		adj[x].pb(y),f[y]=x;
	}
	int mina=n+1;
	for(int i=2;i<=n;i++) if(a[i]>a[f[i]]) chkmin(mina,a[f[i]]);
	ll ans=0;
	if(mina<=n){
		while(a[f[p[mina]]]>mina){
			ans++;
			int x=p[mina],y=f[x];
			swap(p[a[x]],p[a[y]]);
			swap(a[x],a[y]);
			bool fl=0;
			for(auto v:adj[y]) if(a[v]>mina&&a[v]<a[x]) fl=1;
			if(fl) return printf("NO\n"),0;
		}
	}
	ncnt=mina-1;
	if(mina<=n){
		if(!dfs(1,mina)) return printf("NO\n"),0;
	}
	else dfs2(1);
	bool fl=1;
	for(int i=1;i<=n;i++) if(a[i]!=dfn[i]) fl=0;
	if(!fl) return printf("NO\n"),0;
	dfs1(1);
	for(int i=1;i<mina;i++) ans+=dep[p[i]];
	printf("YES\n");
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++) printf("%d ",dfn[i]);
	printf("\n");
	return 0;
}