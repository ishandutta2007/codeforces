#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
using namespace std;
const int N=5e4+9;
int f[N],son[N][2];
ll val[N],sum[N],a[N],sum2[N];
int vir_sz[N],sz[N];
ll vir_sum[N],sz2[N];
bool isroot(int x){return !f[x]||son[f[x]][0]!=x&&son[f[x]][1]!=x;}
void up(int x){
	sz[x]=vir_sz[x]+sz[son[x][0]]+sz[son[x][1]];
	sum[x]	=sum[son[x][0]]+sum[son[x][1]]+vir_sum[x]
			+2*val[son[x][0]]*(sz[x]-sz[son[x][0]])
			+a[x]*(2ll*sz[son[x][1]]*vir_sz[x]+1ll*vir_sz[x]*vir_sz[x]-sz2[x]); 
	val[x]=val[son[x][0]]+val[son[x][1]]+1ll*a[x]*vir_sz[x];
}
void vir_up(int x,int y,int v){
	vir_sz[x]+=v*sz[y];
	sz2[x]+=1ll*v*sz[y]*sz[y];
	vir_sum[x]+=v*sum[y];
}
void rotate(int x){
	int y=f[x],w=son[y][1]==x;
	son[y][w]=son[x][w^1];
	if(son[x][w^1])f[son[x][w^1]]=y;
	if(f[y]){
		int z=f[y];
		if(son[z][0]==y)son[z][0]=x;else if(son[z][1]==y)son[z][1]=x;
	}
	f[x]=f[y];f[y]=x,son[x][w^1]=y;up(y),up(x);
}
void splay(int x){
	int s=1,y;
	while(!isroot(x)){
		y=f[x];
		if(!isroot(y)){if((son[f[y]][0]==y)^(son[y][0]==x))rotate(x);else rotate(y);}
		rotate(x);
	} 
	up(x);
}
void access(int x){for(int y=0;x;y=x,x=f[x])splay(x),vir_up(x,son[x][1],1),son[x][1]=y,vir_up(x,y,-1),up(x);}
void makeroot(int x){access(x);splay(x);}
void link(int x,int y){makeroot(x);makeroot(y);f[x]=y;vir_up(y,x,1);access(x);}
void cut(int x,int y){
	makeroot(x);
	splay(y);
	f[x]=0;son[y][1]=0;up(y);
}
int fa[N];
int main(){
	int n,m;
	scanf("%d",&n);
	rep(i,2,n+1)scanf("%d",&fa[i]);
	rep(i,1,n+1)scanf("%lld",&a[i]),sz[i]=vir_sz[i]=1,val[i]=sum[i]=a[i];
	rep(i,2,n+1)link(i,fa[i]);
	access(1);splay(1);
	printf("%.9lf\n",1.0*sum[1]/n/n);
	scanf("%d",&m);
	while(m--){
		char str[3];
		scanf("%s",str);
		int u,v;
		scanf("%d%d",&u,&v);
		if(str[0]=='P'){
			swap(u,v);
			access(u);
			splay(u);
			splay(v);
			if(!isroot(u)){
				cut(u,fa[u]);
				link(u,v);
				fa[u]=v;
			}
			else{
				cut(v,fa[v]);
				link(v,u);
				fa[v]=u;
			}
		}
		else{
			access(u);
			splay(u);
			a[u]=v;
			up(u);
		}
		access(1);splay(1);
		printf("%.9lf\n",1.0*sum[1]/n/n);
	}
}
/*
5
1 2 2 1
1 2 3 4 5

5
1 2 2 1
1 2 3 4 5
1
P 3 4

*/