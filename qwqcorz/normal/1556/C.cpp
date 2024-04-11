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
void write(long long x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(long long x,char c='\n')
{
	write(x);
	putchar(c);
}
int a[N];
void Multi_test_no_horses()
{
	int n=read();
	long long ans=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++)
	if (i&1)
	{
		long long sum=0,mn=0;
		for (int j=i;j<=n;j++)
		if (j&1) sum+=a[j];
		else
		{
			ans+=max(a[i]+mn-max(sum-a[j],0LL)+1,0LL);
			if (j-i==1) ans--;
			sum-=a[j];
			mn=min(mn,sum-a[i]);
			if (sum<0) break;
		}
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