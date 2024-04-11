#include<bits/stdc++.h>
using namespace std;

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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
inline double f(int d,int x)
{
	return x+1.0*d/(x+1);
}
inline int GetMin(int d)
{
	int l=0,r=d-1;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (f(d,mid+1)-f(d,mid)<=0) l=mid+1;
							   else r=mid-1;
	}
	return ceil(min(f(d,l),f(d,max(r,0))));
}

signed main()
{
	int T=read();
	while (T--)
	{
		int n=read(),d=read();
		puts(GetMin(d)<=n?"YES":"NO");
	}
	
	return 0;
}