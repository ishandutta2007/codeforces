#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
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
int a[N],b[N],n,m;
void leave(double &x,int i)
{
	x-=(m+x)/a[i];
}
void land(double &x,int i)
{
	x-=(m+x)/b[i];
}
bool check(double x)
{
	for (int i=1;i<=n;i++)
	{
		leave(x,i);
		if (x<-eps) return 0;
		land(x,i%n+1);
		if (x<-eps) return 0;
	}
	return 1;
}

signed main()
{
	n=read();
	m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	double l=0,r=1e9;
	if (!check(r)) puts("-1");
	else
	{
		for (int i=1;i<=233;i++)
		{
			double mid=(l+r)/2;
			if (check(mid)) r=mid;
					   else l=mid;
		}
		printf("%.10lf",l);
	}

	return 0;
}