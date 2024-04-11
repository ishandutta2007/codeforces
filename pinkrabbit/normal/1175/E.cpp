#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 500005
#define P 500000
#define ll long long
#define mod 998244353
int n,m,q,k;
int l[MN],r[MN],p[MN];
int mxr[MN];
int h[MN],nxt[MN],to[MN],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
int faz[MN][20],dep[MN];
void dfs(int u){
	for(int i=h[u];i;i=nxt[i]){
		dep[to[i]]=dep[u]+1;
		for(int j=1;1<<j<dep[to[i]];++j)faz[to[i]][j]=faz[faz[to[i]][j-1]][j-1];
		dfs(to[i]);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n)scanf("%d%d",l+i,r+i),p[i]=i;
	sort(p+1,p+n+1,[](int i,int j){return r[i]>r[j];});
	F(i,0,P)mxr[i]=-1;
	int mx=500000;
	F(I,1,n){
		int i=p[I];
		F2(j,l[i],min(mx,r[i]))mxr[j]=r[i];
		mx=min(mx,l[i]);
	}
	memset(faz,-1,sizeof faz);
	F(i,0,P)if(~mxr[i])ins(mxr[i],i),faz[i][0]=mxr[i];
	F(i,0,P)if(!~mxr[i])dep[i]=1,dfs(i);
	F(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		int z=x;
		for(int j=19;~j;--j)if(~faz[z][j])
			if(faz[z][j]<y)z=faz[z][j];
		z=faz[z][0];
		if(~z)printf("%d\n",dep[x]-dep[z]);
		else puts("-1");
	}
	return 0;
}