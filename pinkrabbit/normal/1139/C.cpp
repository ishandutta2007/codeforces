#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
typedef long long LL;
const int Mod=1e9+7;
int n,m,q,k;
int a[MN],b[MN],f[MN],g[MN],c;
int h[MN],nxt[MM],to[MM],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
void d(int u){
	b[u]=1;++c;
	for(int i=h[u];i;i=nxt[i])if(!b[to[i]])d(to[i]);
}
int main(){int x,y,z;
	scanf("%d%d",&n,&k);
	F(i,2,n)scanf("%d%d%d",&x,&y,&z),(!z?(ins(x,y),ins(y,x)):void(0));
	int Ans=1;F(i,1,k)Ans=(LL)Ans*n%Mod;
	F(i,1,n)if(!b[i]){c=0,d(i);int s=1;F(j,1,k)s=(LL)s*c%Mod;Ans=(Ans-s+Mod)%Mod;}
	printf("%d\n",Ans);
	return 0;
}

// lg