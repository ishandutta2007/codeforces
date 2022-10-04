#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
int n,m,k;long long Ans;
int a[MN],b[MN],f[MN],g[MN];
int h[MN],nxt[MM],to[MM],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i);
	b[n+1]=1e9+7;
	dF(i,n,1)Ans+=b[i]=max(0,min(a[i],b[i+1]-1));
	printf("%lld\n",Ans);
	return 0;
}

// lg