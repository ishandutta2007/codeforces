#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int p=998244353;

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
int fact[N],inv[N];
void ysgs(int n)
{
	for (int i=fact[0]=1;i<=n;i++) fact[i]=1LL*fact[i-1]*i%p;
	inv[n]=power(fact[n],p-2);
	for (int i=n;i>=1;i--) inv[i-1]=1LL*inv[i]*i%p;
}
int f[N][N],g[N][N],h[N][N];
void Multi_test_no_horses()
{
	int n=read(),x=read(),ans=power(x,n);
	ysgs(500);
	g[0][0]=1;
	for (int i=1;i<=x;i++) h[0][i]=(h[0][i-1]+g[0][i-1])%p;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=x;j++)
	{
		for (int k=1;k<=i;k++)
		g[i][j]=(g[i][j]+1LL*h[i-k][j]*inv[k])%p;
		h[i][j]=(h[i][j-1]+g[i][j-1])%p;
	}
	for (int i=1;i<=x;i++) f[1][i]=1;
	for (int k=2;k<=n;k++)
	for (int i=k;i<=x;i++)
	for (int j=0;j<k;j++)
	f[k][i]=(f[k][i]+1LL*f[k-j][i-(k-1)]*h[j][k])%p;
	for (int i=1;i<=x;i++) ans=(ans-1LL*f[n][i]*fact[n]%p+p)%p;
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