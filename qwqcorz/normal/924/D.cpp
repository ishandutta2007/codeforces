#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
const double eps=1e-8;

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
	double xx,yy;
	bool operator <(const point &a)const
	{
		if (x==a.x) return y>a.y;
		return x<a.x;
	}
}a[N];
double p[N*2];
int t[N*2],nn;
void add(int x)
{
	for (;x<=nn*2;x+=x&-x) t[x]++;
}
int query(int x)
{
	int ret=0;
	for (;x;x-=x&-x) ret+=t[x];
	return ret;
}

signed main()
{
	memset(t,0,sizeof(t));
	int n=nn=read(),w=read(),cnt=0,ans=0;
	for (int i=1;i<=n;i++)
	{
		int x=read(),v=read();
		a[i].xx=1.0*x/(v-w);
		a[i].yy=1.0*x/(v+w);
		p[++cnt]=a[i].xx;
		p[++cnt]=a[i].yy;
	}
	sort(p+1,p+1+cnt);
	cnt=unique(p+1,p+1+cnt)-p-1;
	for (int i=1;i<=n;i++)
	{
		a[i].x=lower_bound(p+1,p+1+cnt,a[i].xx)-p;
		a[i].y=lower_bound(p+1,p+1+cnt,a[i].yy)-p;
	}
	sort(a+1,a+1+n);
	for (int i=n;i>=1;i--)
	{
		ans+=query(a[i].y);
		add(a[i].y);
	}
	print(ans);

	return 0;
}