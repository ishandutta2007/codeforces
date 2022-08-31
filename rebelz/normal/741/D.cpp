#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int inf=1<<30;
int n,tot,sum;
int siz[500005],v[500005],nxt[500005],h[500005],c[500005],md[1<<23],fc[500005],dep[500005],ans[500005],son[500005];
bool vis[500005];

void addedge(int x,int y,int z){v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; h[x]=tot;}

void dfs1(int u){
	siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		dep[v[p]]=dep[u]+1,fc[v[p]]=fc[u]^(1<<c[p]);
		dfs1(v[p]);
		siz[u]+=siz[v[p]];
		if(siz[v[p]]>siz[son[u]]) son[u]=v[p];
	}
}

void calc(int u,int d){
	sum=max(sum,dep[u]+md[fc[u]]-2*d);
	for(int i=0;i<=21;i++) sum=max(sum,dep[u]+md[fc[u]^(1<<i)]-2*d);
	for(int p=h[u];p;p=nxt[p]) if(!vis[v[p]]) calc(v[p],d);
}

void add(int u,int w){
	md[fc[u]]=w?max(md[fc[u]],dep[u]):-inf;
	for(int p=h[u];p;p=nxt[p]) if(!vis[v[p]]) add(v[p],w);
}

void dfs2(int u,int k){
	for(int p=h[u];p;p=nxt[p]) if(v[p]!=son[u]) dfs2(v[p],0);
	if(son[u]) dfs2(son[u],1),vis[son[u]]=1;
	for(int p=h[u];p;p=nxt[p]) if(v[p]!=son[u]) calc(v[p],dep[u]),add(v[p],1);
	for(int p=h[u];p;p=nxt[p]) ans[u]=max(ans[u],ans[v[p]]);
	sum=max(sum,md[fc[u]]-dep[u]);
	for(int i=0;i<=21;i++) sum=max(sum,md[fc[u]^(1<<i)]-dep[u]);
	md[fc[u]]=max(md[fc[u]],dep[u]);
	ans[u]=max(ans[u],sum);
	if(son[u]) vis[son[u]]=0;
	if(!k) add(u,0),sum=-inf;
}

int main(){
	n=readint();
	int x; char y;
	for(int i=2;i<=n;i++){
		x=readint(); scanf("%c",&y);
		addedge(x,i,y-'a');
	}
	for(int i=1;i<(1<<23);i++) md[i]=-inf;
	dfs1(1);
	dfs2(1,0);
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}