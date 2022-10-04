#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
#define Hard Luogu
int n,Ans;
int a[1000010],b[1000010],D[2000010],T,v[2000010];

int h[2000010],nxt[4000010],to[4000010],vi[4000010],tot=1;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}

int V,E,M1,M2;
void DFS(int u){
	v[u]=1; ++V;
	if(u>M2) M2=u;
	if(M2>M1) swap(M2,M1);
	eF(i,u) if(!vi[i]){
		vi[i]=1, vi[i^1]=1, ++E;
		if(!v[to[i]]) DFS(to[i]);
	}
}

int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d%d",a+i,b+i), D[++T]=a[i], D[++T]=b[i];
	sort(D+1,D+T+1); T=unique(D+1,D+T+1)-D-1;
	F(i,1,n) a[i]=lower_bound(D+1,D+T+1,a[i])-D, b[i]=lower_bound(D+1,D+T+1,b[i])-D;
	F(i,1,n) ins(a[i],b[i]), ins(b[i],a[i]);
	F(i,1,T) if(!v[i]){
		int LV=V,LE=E;
		M1=M2=0;
		DFS(i);
		if(E-LE>V-LV) return 0*puts("-1");
		if(E-LE==V-LV) Ans=max(Ans,D[M1]);
		else Ans=max(Ans,D[M2]);
	}
	printf("%d",Ans);
	return 0;
}