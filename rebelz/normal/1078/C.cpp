#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;
int n,tot;
int d[300005][3],v[600005],nxt[600005],h[300005],g[3];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

int mod(int x){return x>=cys?x-cys:x;}

int power(int x,int p){
	int ret=1;
	for(;p;p>>=1,x=1ll*x*x%cys) if(p&1) ret=1ll*ret*x%cys;
	return ret;
}

void dfs(int u,int fa){
	d[u][0]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs(v[p],u);
		g[0]=1ll*d[u][0]*mod(d[v[p]][0]+d[v[p]][2])%cys;
		g[1]=mod(1ll*d[u][0]*d[v[p]][2]%cys+1ll*d[u][1]*mod(d[v[p]][0]+mod(d[v[p]][2]*2))%cys);
		g[2]=mod(mod(1ll*d[u][0]*mod(d[v[p]][0]+d[v[p]][1])%cys+1ll*d[u][1]*mod(d[v[p]][0]+d[v[p]][1])%cys)+1ll*d[u][2]*mod(d[v[p]][0]+mod(d[v[p]][2]*2))%cys);
		swap(d[u],g);
	}
//	cout<<"TEST "<<u<<' '<<d[u][0]<<' '<<d[u][1]<<' '<<d[u][2]<<endl;
}

int main(){
	n=readint();
	int x,y;
	for(int i=1;i<=n-1;i++){
		x=readint(); y=readint();
		addedge(x,y);
	}
	dfs(1,-1);
	printf("%d\n",mod(d[1][0]+d[1][2]));
	return 0;
}