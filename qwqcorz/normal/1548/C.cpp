#include<bits/stdc++.h>
using namespace std;
const int N=3e6+5;
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
int dp[N][3],fact[N],inv[N];
int C(int n,int m)
{
	return 1LL*fact[n]*inv[m]%p*inv[n-m]%p;
}
void ysgs(int n)
{
	for (int i=fact[0]=1;i<=n;i++) fact[i]=1LL*fact[i-1]*i%p;
	inv[n]=power(fact[n],p-2);
	for (int i=n;i>=1;i--) inv[i-1]=1LL*inv[i]*i%p;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),q=read(),inv3=power(3,p-2);
	dp[0][0]=dp[0][1]=dp[0][2]=n;
	ysgs(n*3+1);
	for (int i=1;i<=3*n;i++)
	{
		dp[i][0]=(C(3*n+1,i+1)+dp[i-1][1]*2LL+dp[i-1][2])%p*inv3%p;
		dp[i][1]=(dp[i][0]-dp[i-1][1]+p)%p;
		dp[i][2]=(dp[i][1]-dp[i-1][2]+p)%p;
	}
	while (q--) print(dp[read()][0]);
	
	return 0;
}