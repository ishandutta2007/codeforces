#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define eF(h,i,u) for(int i=h[u];i;i=nxt[i])
using namespace std;

int n,m,H,Ans;
int Ut[100001];

int h[100001],h2[100001],nxt[500001],to[500001],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
inline void ins2(int x,int y){nxt[++tot]=h2[x];to[tot]=y;h2[x]=tot;}

bool vis[100001];
int dfn[100001],idf[100001],siz[100001],SCC[100001],Out[100001],cnt,CCn;

int h3[100001];
inline void ins3(int x,int y){nxt[++tot]=h3[x];to[tot]=y;h3[x]=tot;}

bool check(int Ut1,int Ut2){return (Ut2-Ut1+H)%H==1;}

void init(){
	int x,y;
	scanf("%d%d%d",&n,&m,&H);
	F(i,1,n) scanf("%d",Ut+i);
	F(i,1,m){
		scanf("%d%d",&x,&y);
		if(check(Ut[x],Ut[y])) ins(x,y),ins2(y,x);
		if(check(Ut[y],Ut[x])) ins(y,x),ins2(x,y);
	}
}

void DFS1(int u){
	vis[u]=1;
	eF(h,i,u)
		if(!vis[to[i]]) DFS1(to[i]);
	dfn[u]=++cnt; idf[cnt]=u;
}

void DFS2(int u){
	vis[u]=1; SCC[u]=CCn; ++siz[CCn]; ins3(CCn,u);
	eF(h2,i,u)
		if(!vis[to[i]]) DFS2(to[i]);
}

void Kosaraju(){
	F(i,1,n) if(!vis[i]) DFS1(i);
	memset(vis,0,sizeof vis);
	dF(i,n,1) if(!vis[idf[i]]) ++CCn, DFS2(idf[i]);
	F(u,1,CCn){
		eF(h3,i,u)
			eF(h,j,to[i])
				if(SCC[to[j]]!=u)
					Out[u]=1; goto ed;
		ed : ;
	}
	siz[Ans=0]=n+1;
	F(i,1,CCn) if(!Out[i]&&siz[Ans]>siz[i]) Ans=i;
}

int main(){
	init();
	Kosaraju();
	printf("%d\n",siz[Ans]);
	eF(h3,i,Ans) printf("%d ",to[i]);
	return 0;
}