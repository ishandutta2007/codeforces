#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])

int n,dep[1000001],buk[1000001],siz[1000001],son[1000001];
int Ans[1000001];

int h[1000001],nxt[2000001],to[2000001],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}

void DFS1(int u,int f){
	siz[u]=1; dep[u]=dep[f]+1;
	eF(i,u) if(to[i]!=f){
		DFS1(to[i],u);
		siz[u]+=siz[to[i]];
		if(siz[to[i]]>siz[son[u]]) son[u]=to[i];
	}
}

void DFS3(int u,int f,int k,int I=0){
	buk[dep[u]]+=k;
	if(k==1){
		if(buk[dep[u]]>buk[Ans[I]]) Ans[I]=dep[u];
		else if(buk[dep[u]]==buk[Ans[I]]&&dep[u]<Ans[I]) Ans[I]=dep[u];
	}
	eF(i,u) if(to[i]!=f)
		DFS3(to[i],u,k,I);
}

void DFS2(int u,int f){
	eF(i,u) if(to[i]!=f&&to[i]!=son[u]){
		DFS2(to[i],u);
		DFS3(to[i],u,-1);
	}
	Ans[u]=dep[u];
	++buk[dep[u]];
	if(son[u]){
		DFS2(son[u],u);
		Ans[u]=buk[Ans[son[u]]]>1?Ans[son[u]]:dep[u];
		eF(i,u) if(to[i]!=f&&to[i]!=son[u]){
			DFS3(to[i],u,1,u);
		}
	}
}

int main(){
	int x,y;
	scanf("%d",&n);
	F(i,2,n) scanf("%d%d",&x,&y), ins(x,y), ins(y,x);
	DFS1(1,0);
	DFS2(1,0);
	F(i,1,n) printf("%d\n",Ans[i]-dep[i]);
	return 0;
}