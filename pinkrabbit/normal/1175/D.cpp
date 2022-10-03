#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
int n,m,q,k;
ll a[MN],b[MN],f[MN],g[MN],s;
int h[MN],nxt[MM],to[MM],tot;
inline void ins(int x,int y){nxt[++tot]=h[x];to[tot]=y;h[x]=tot;}
int main(){
	scanf("%d%d",&n,&k);
	F(i,1,n)scanf("%lld",a+i);
	dF(i,n,1)a[i]+=a[i+1];
	s=a[1];
	sort(a+2,a+n+1);
	F(i,1,k-1)s+=a[n-i+1];
	printf("%lld\n",s);
	return 0;
}