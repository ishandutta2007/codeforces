#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
int n,m,q,k;
int a[MN],b[MN],f[MN],g[MN];
int h[MN],nxt[MM],to[MM],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	F(i,1,n)scanf("%d",a+i);
	sort(a+1,a+n+1);
	int t=m/(k+1);
	long long ans=(long long)a[n]*k+a[n-1];
	ans*=t;
	ans+=(long long)a[n]*(m-t*(k+1));
	printf("%lld\n",ans);
	return 0;
}