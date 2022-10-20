#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

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
int a[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		double ans=-1e18;
		long long sum=0,sum1=0;
		int n=read();
		for (int i=1;i<=n;i++) sum+=a[i]=read();
		sort(a+1,a+1+n);
		for (int i=1;i<=n;i++) sum1+=a[i],ans=max(ans,1.0*sum1/i+1.0*(sum-sum1)/(n-i));
		printf("%.9lf\n",ans);
	}
	
	return 0;
}