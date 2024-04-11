#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2")
#define ll long long
using namespace std;
const int N=2525;
const int M=50;
const int p=2520;

ll read()
{
	ll s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
int MOD[114514];
int Mod(register int x)
{
	if (~MOD[x]) return MOD[x];
	return MOD[x]=x%p;
}
ll gcd(register ll x,register ll y)
{
	return !y?x:gcd(y,x%y);
}
int LCM[N][N];
inline ll lcm(register ll x,register ll y)
{
	if (!x||!y) return x|y;
	if (LCM[x][y]) return LCM[x][y];
	return LCM[x][y]=x/gcd(x,y)*y;
}
int nd[N],d[M],cnt=0,a[21];
ll dp[21][N][M][2];
ll calc(register ll n)
{
	register ll tmp=n;
	register int m=0;
	while (tmp)
	{
		a[++m]=tmp%10;
		tmp/=10;
	}
	memset(dp,0,sizeof(dp));
//	for (register int i=m+1;i>=1;i--)
//	for (register int j=0;j<p;j++)
//	for (register int k=1;k<=cnt;k++) dp[i][j][k][0]=dp[i][j][k][1]=0;
	dp[m+1][0][1][1]=1;
	for (register int i=m;i>=1;i--)
	for (register int j=0;j<p;j++)
	for (register int k=1;k<=cnt;k++)
	{
//		print(i,' ');
//		print(j,' ');
//		print(k);
		if (dp[i+1][j][k][0]) for (register int t=0;t<=9;t++) dp[i][Mod(j*10+t)][nd[lcm(d[k],t)]][0]+=dp[i+1][j][k][0];
		if (dp[i+1][j][k][1])
		{
			for (register int t=0;t<a[i];t++) dp[i][Mod(j*10+t)][nd[lcm(d[k],t)]][0]+=dp[i+1][j][k][1];
			dp[i][Mod(j*10+a[i])][nd[lcm(d[k],a[i])]][1]+=dp[i+1][j][k][1];
		}
	}
	ll ret=0;
	for (register int j=0;j<p;j++)
	for (register int k=1;k<=cnt;k++)
	if (j%d[k]==0)
	ret+=dp[1][j][k][0]+dp[1][j][k][1];
//	print(ret);
	return ret;
}

signed main(int Recall,char *_902_[])
{
	memset(MOD,-1,sizeof(MOD));
	for (int i=1;i<=p;i++)
	if (p%i==0)
	{
		d[++cnt]=i;
		nd[i]=cnt;
	}
	int T=read();
	while (T--)
	{
		ll l=read(),r=read();
		print(calc(r)-calc(l-1));
	}

	return 0;
}
/*
10
9000000000000000000 9000000000000000000
9000000000000000000 9000000000000000000
9000000000000000000 9000000000000000000
9000000000000000000 9000000000000000000
9000000000000000000 9000000000000000000
9000000000000000000 9000000000000000000
9000000000000000000 9000000000000000000
9000000000000000000 9000000000000000000
9000000000000000000 9000000000000000000
9000000000000000000 9000000000000000000
*/