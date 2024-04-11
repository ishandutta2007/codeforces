#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,m,tot,ansx,ansy;
int v[200005],nxt[200005],h[100005],dep[100005],f[100005][20],siz[100005];

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u){
	siz[u]=1;
	for(int i=1;i<=19;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==f[u][0]) continue;
		f[v[p]][0]=u; dep[v[p]]=dep[u]+1;
		dfs(v[p]);
		siz[u]+=siz[v[p]];
	}
}

int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=19;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	ansx=siz[x],ansy=siz[y];
	return f[x][0];
}

int find(int x,int y){
	for(int i=19;i>=0;i--) if(y>=(1<<i)) x=f[x][i],y-=1<<i;
	return x;
}

int main(){
	n=readint();
	int x,y,z;
	for(int i=1;i<=n-1;i++){
		x=readint(); y=readint();
		addedge(x,y);
	}
	dep[1]=1; dfs(1);
	m=readint();
	while(m--){
		x=readint(); y=readint();
		z=lca(x,y);
		if(x==y) printf("%d\n",n);
		else if(dep[x]-dep[z]==dep[y]-dep[z]) printf("%d\n",siz[1]-ansx-ansy);
		else if((dep[x]-dep[z]+dep[y]-dep[z])%2==1) printf("0\n");
		else if(dep[x]-dep[z]>dep[y]-dep[z]) printf("%d\n",siz[find(x,(dep[x]+dep[y]-dep[z]-dep[z])/2)]-siz[find(x,(dep[x]+dep[y]-dep[z]-dep[z])/2-1)]);
		else printf("%d\n",siz[find(y,(dep[x]+dep[y]-dep[z]-dep[z])/2)]-siz[find(y,(dep[x]+dep[y]-dep[z]-dep[z])/2-1)]);
	}
	return 0;
}