#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;

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
int n,l,x[N],b[N];
int from[N];
double dp[N];
bool check(double k)
{
	for (int i=1;i<=n;i++)
	{
		dp[i]=1e18;
		for (int j=0;j<i;j++)
		if (dp[j]+sqrt(abs(x[i]-x[j]-l))-b[i]*k<dp[i])
		dp[i]=dp[j]+sqrt(abs(x[i]-x[j]-l))-b[i]*k,from[i]=j;
	}
	return dp[n]<=0;
}
void output(int x)
{
	if (!x) return;
	output(from[x]);
	print(x,' ');
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	n=read(),l=read();
	for (int i=1;i<=n;i++) x[i]=read(),b[i]=read();
	double l=1e-6,r=1e6;
	for (int T=50;T--;)
	{
		double mid=(l+r)/2;
		if (check(mid)) r=mid;
				   else l=mid;
	}
	check(r);
	output(n);
	
	return 0;
}