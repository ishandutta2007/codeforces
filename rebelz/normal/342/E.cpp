#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,tot,cnt;
int v[200005],nxt[200005],h[100005],f[100005][20],dep[100005],d[100005],vec[100005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u){
	for(int i=1;i<=15;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==f[u][0]) continue;
		f[v[p]][0]=u,d[v[p]]=dep[v[p]]=d[u]+1;
		dfs(v[p]);
	}
}

void dfs1(int u){
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==f[u][0]) continue;
		dfs1(v[p]);
		d[u]=min(d[u],d[v[p]]+1);
	}
}

void dfs2(int u){
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==f[u][0]) continue;
		d[v[p]]=min(d[v[p]],d[u]+1);
		dfs2(v[p]);
	}
}

int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=15;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=15;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

int dist(int x,int y){
	int l=lca(x,y);
	return dep[x]+dep[y]-2*dep[l];
}

int main(){
	n=readint(); m=readint();
	int x,y,ans;
	for(int i=1;i<=n-1;i++){
		x=readint(); y=readint();
		addedge(x,y);
	}
	dfs(1);
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		if(x==1) vec[++cnt]=y;
		else{
			if(cnt>=250){
				for(int j=1;j<=cnt;j++) d[vec[j]]=0;
				cnt=0;
				dfs1(1);
				dfs2(1);
			}
			ans=d[y];
			for(int j=1;j<=cnt;j++) ans=min(ans,dist(y,vec[j]));
			printf("%d\n",ans);
		}
	}
	return 0;
}