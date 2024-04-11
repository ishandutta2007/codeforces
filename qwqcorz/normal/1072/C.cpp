#include<bits/stdc++.h>
#define int long long
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
bool a[N];
int n,m;
bool check(int mid,bool flag)
{
	if (mid*(mid+1)/2>n+m) return 0;
	int x=n,y=m,sum=mid*(mid+1)/2,tot=0;
	for (int i=1;i<=mid;i++) a[i]=0;
	for (int i=mid;i>=1;i--)
	if (x>=i)
	{
		x-=i;
		a[i]=1;
		sum-=i;
		tot++;
	}
	if (sum<=y)
	{
		if (flag)
		{
			print(tot);
			for (int i=1;i<=mid;i++) if (a[i]) print(i,' ');
			putchar('\n');
			print(mid-tot);
			for (int i=1;i<=mid;i++) if (!a[i]) print(i,' ');
		}
		return 1;
	}
	return 0;
}

signed main()
{
	n=read();
	m=read();
	int l=0,r=1e5;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (check(mid,0)) l=mid+1;
					 else r=mid-1;
	}
	check(r,1);

	return 0;
}