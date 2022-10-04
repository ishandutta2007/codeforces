#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
int n,m,q,x,y,S;
int v[400001];
int h[400001],nxt[400001],to[400001],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
void D(int u){for(int i=h[u];i;i=nxt[i]) if(!v[to[i]]) v[to[i]]=1, D(to[i]);}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	while(q--) scanf("%d%d",&x,&y), ins(x,n+y), ins(n+y,x);
	for(int i=1;i<=n+m;++i) if(!v[i]) ++S, v[i]=1, D(i);
	printf("%d",S-1);
	return 0;
}