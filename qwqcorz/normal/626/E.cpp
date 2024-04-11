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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
bool up(long double &x,long double y){if (x<y) return x=y,1;return 0;}
long double ans=-1;
long long sum[N];
int a[N],n,x=0,y=0;
long double calc(int x,int y)
{
	return 1.0L*(sum[x]-sum[x-y-1]+sum[n]-sum[n-y])/(y*2+1)-a[x];
}
long long alb(int x,int y)
{
	return sum[x]-sum[x-y-1]+sum[n]-sum[n-y];
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for (int i=1;i<=n;i++)
	{
		int l=0,r=min(i-1,n-i);
		while (l<r)
		{
			int mid=(l+r)/2;
			if (alb(i,mid+1)*(mid*2+1)>alb(i,mid)*(mid*2+3)) l=mid+1;
														else r=mid;
		}
		if (up(ans,calc(i,l))) x=i,y=l;
	}
	print(y*2+1);
	for (int i=0;i<=y;i++) print(a[x-i],' ');
	for (int i=0;i<y;i++) print(a[n-i],' ');
	
	return 0;
}