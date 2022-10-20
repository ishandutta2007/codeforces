#include<bits/stdc++.h>
#define ll long long
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
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
struct node
{
	int x,y;
	bool operator <(const node &a)const
	{
		return x<a.x;
	}
}a[N];
ll ans=0;

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i].x=read(),ans+=a[i].y=read();
	sort(a+1,a+1+n);
	int Max=a[1].x+a[1].y;
	for (int i=2;i<=n;i++)
	{
		ans+=max(a[i].x-Max,0);
		Max=max(Max,a[i].x+a[i].y);
	}
	print(ans);

	return 0;
}