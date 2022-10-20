#include<bits/stdc++.h>
using namespace std;
const int N=105;

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
struct node
{
	int t,l,r;
	bool operator <(const node &a)const
	{
		return t<a.t;
	}
}a[N];

int main()
{
	int T=read();
	while (T--)
	{
		int n=read(),m=read();
		for (int i=1;i<=n;i++)
		{
			a[i].t=read();
			a[i].l=read();
			a[i].r=read();
		}
		a[0].t=0;
		a[n+1].t=-233;
		sort(a+1,a+1+n);
		int l=m,r=m;
		for (int i=n;i>1;i--)
		if (a[i].t==a[i-1].t)
		{
			a[i-1].l=max(a[i-1].l,a[i].l);
			a[i-1].r=min(a[i-1].r,a[i].r);
		}
		bool flag=1;
		for (int i=1;i<=n;i++)
		if (a[i].t!=a[i-1].t)
		{
			l=max(l-(a[i].t-a[i-1].t),a[i].l);
			r=min(r+(a[i].t-a[i-1].t),a[i].r);
			if (r<l)
			{
				flag=0;
				break;
			}
		}
		puts(flag?"YES":"NO");
	}

	return 0;
}