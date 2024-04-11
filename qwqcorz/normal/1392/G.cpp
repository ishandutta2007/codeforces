#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
const int K=20;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct permutation
{
	int p[K],k;
	permutation(int _k=0){k=_k;for (int i=0;i<k;i++) p[i]=i;}
	void mySwap(int u,int v){swap(p[u],p[v]);}
	friend permutation operator *(permutation a,permutation b)
	{
		permutation ret(a.k);
		for (int i=0;i<a.k;i++) ret.p[i]=b.p[a.p[i]];
		return ret;
	}
}p[N];
char a[K+5],b[K+5];
int F[1<<K],G[1<<K];

signed main()
{
	int n=read(),m=read(),k=read();
	scanf("%s%s",a,b);
	int A=0,B=0;
	for (int i=0;i<k;i++) A+=a[i]=='1';
	for (int i=0;i<k;i++) B+=b[i]=='1';
	for (int i=1;i<=n;i++)
	{
		p[i]=permutation(k);
		int u=read()-1,v=read()-1;
		p[i].mySwap(u,v);
	}
	memset(F,0x3f,sizeof(F));
	p[n+1]=permutation(k);
	for (int i=n;i>=1;i--) p[i]=p[i]*p[i+1];
	for (int i=1;i<=n;i++)
	{
		int S=0;
		for (int j=0;j<k;j++) if (a[j]=='1') S|=1<<p[i].p[j];
		F[S]=min(F[S],i);
	}
	for (int i=2;i<=n+1;i++)
	{
		int S=0;
		for (int j=0;j<k;j++) if (b[j]=='1') S|=1<<p[i].p[j];
		G[S]=max(G[S],i);
	}
	for (int i=(1<<k)-1;i>=0;i--)
	for (int j=0;j<k;j++)
	if (~i>>j&1)
		F[i]=min(F[i],F[i|1<<j]),
		G[i]=max(G[i],G[i|1<<j]);
	int ans=-1,u=0,v=0;
	for (int i=0;i<(1<<k);i++)
	if (G[i]-F[i]>=m&&ans<__builtin_popcount(i))
	{
		ans=__builtin_popcount(i);
		u=F[i],v=G[i];
	}
	print(ans+(k-(A-ans)-(B-ans)-ans));
	print(u,' '),print(v-1);
	
	return 0;
}