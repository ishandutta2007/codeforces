#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int n,k,a[N],sum[N];
bool check(int x)
{
	int Min=n*2;
	for (int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1];
		if (a[i]>=x) sum[i]++;
				else sum[i]--;
		if (i>=k)
		{
			Min=min(Min,sum[i-k]);
			if (sum[i]-Min>0) return 1;
		}
	}
	return 0;
}

signed main()
{
	n=read();
	k=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int l=1,r=n;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (check(mid)) l=mid+1;
				   else r=mid-1;
	}
	print(r);

	return 0;
}