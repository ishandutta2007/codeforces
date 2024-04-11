#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
#define mk make_pair
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
struct point
{
	int x,y;
	bool operator <(const point &a)const
	{
//		print(x,' ');
//		print(y,':');
//		print(a.x,' ');
//		print(a.y);
		return x*x+y*y<a.x*a.x+a.y*a.y;
	}
	point operator +(pair<int,int>a)const
	{
		point ret=*this;
		ret.x+=a.x;
		ret.y+=a.y;
		return ret;
	}
}now;
pair<pair<int,int>,int>a[N];
int ans[N];

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++)
	{
		a[i].x.x=read();
		a[i].x.y=read();
		a[i].y=i;
	}
	while (1)
	{
		now.x=now.y=0;
		for (int i=1;i<=n;i++)
		if ((now+mk(a[i].x.x,a[i].x.y))<(now+mk(-a[i].x.x,-a[i].x.y)))
		{
			now=now+mk(a[i].x.x,a[i].x.y);
			ans[a[i].y]=1;
		}
		else
		{
			now=now+mk(-a[i].x.x,-a[i].x.y);
			ans[a[i].y]=-1;
		}
		if (sqrt(now.x*now.x+now.y*now.y)<=1.5e6)
		{
			for (int i=1;i<=n;i++) print(ans[i],' ');
			return 0;
		}
		random_shuffle(a+1,a+1+n);
	}

	return 0;
}