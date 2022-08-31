#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,tot;
ld fac[55],d[55][55],g[55],tmp[55];
int v[105],nxt[105],h[55],siz[55];

ld C(int n,int m){return n<m?0:fac[n]/fac[m]/fac[n-m];}

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
	siz[u]=d[u][0]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs(v[p],u);
		for(int j=0;j<=siz[v[p]];j++){
			g[j]=0;
			for(int k=0;k<j;k++) g[j]+=0.5*d[v[p]][k];
			g[j]+=(siz[v[p]]-j)*d[v[p]][j];
		}
		for(int j=0;j<=siz[u]+siz[v[p]];j++) tmp[j]=0;
		for(int j=0;j<siz[u];j++)
			for(int k=0;k<=siz[v[p]];k++)
				tmp[j+k]+=d[u][j]*g[k]*C(siz[u]+siz[v[p]]-j-k-1,siz[u]-j-1)*C(j+k,j);
		siz[u]+=siz[v[p]];
		for(int j=0;j<siz[u];j++) d[u][j]=tmp[j];
	}
}

int main(){
	n=readint();
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i;
	for(int i=1;i<=n-1;i++) addedge(readint(),readint());
	for(int i=1;i<=n;i++){
		memset(d,0,sizeof(d));
		dfs(i,-1);
		printf("%.10Lf\n",d[i][n-1]/fac[n-1]);
	}
	return 0;
}