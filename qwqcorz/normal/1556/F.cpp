#include<bits/stdc++.h>
using namespace std;
const int N=14;
const int S=1<<N;
const int p=1e9+7;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int power(int a,int b)
{
	int ret=1;
	while (b)
	{
		if (b&1) ret=1LL*ret*a%p;
		a=1LL*a*a%p;
		b/=2;
	}
	return ret;
}
#define have(i,j) ((i)>>(j)&1)
int g[S],to[S][N],e[N][N],a[N];
void Multi_test_no_horses()
{
	int n=read(),s=1<<n;
	for (int i=0;i<n;i++) a[i]=read();
	for (int i=0;i<n;i++)
	for (int j=0;j<n;j++) if (i!=j) e[i][j]=1LL*a[i]*power(a[i]+a[j],p-2)%p;
	for (int i=0;i<s;i++)
	for (int j=0;j<n;j++) if (!have(i,j))
	{
		to[i][j]=1;
		for (int k=0;k<n;k++) if (have(i,k)) to[i][j]=1LL*to[i][j]*e[k][j]%p;
	}
	for (int i=1;i<s;i++)
	for (int j=i&(i-1);j;j=(j-1)&i)
	{
		int now=1;
		for (int k=0;k<n;k++) if (have(i^j,k)) now=1LL*now*to[j][k]%p;
		g[i]=(g[i]+(1LL-g[j]+p)*now)%p;
	}
	int ans=0;
	for (int i=1;i<s;i++)
	{
		int now=1;
		for (int k=0;k<n;k++) if (!have(i,k)) now=1LL*now*to[i][k]%p;
		ans=(ans+(1LL-g[i]+p)*now%p*__builtin_popcount(i))%p;
	}
	print(ans);
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
	int T=1;
//	int T=read();
	while (T--) Multi_test_no_horses();
	
	return 0;
}