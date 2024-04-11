#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int inf=1e9;

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
int lx[N],ly[N],rx[N],ry[N];
int x1=-inf,y1=-inf,x2=inf,y2=inf;
void cdq(int l,int r)
{
	if (l==r)
	{
		if (x1<=x2&&y1<=y2)
		{
			print(x1,' ');
			print(y1);
			exit(0);
		}
		return;
	}
	int mid=(l+r)/2;
	int tx1=x1,ty1=y1,tx2=x2,ty2=y2;
	for (int i=mid+1;i<=r;i++) x1=max(x1,lx[i]);
	for (int i=mid+1;i<=r;i++) y1=max(y1,ly[i]);
	for (int i=mid+1;i<=r;i++) x2=min(x2,rx[i]);
	for (int i=mid+1;i<=r;i++) y2=min(y2,ry[i]);
	cdq(l,mid);
	x1=tx1,y1=ty1,x2=tx2,y2=ty2;
	for (int i=l;i<=mid;i++) x1=max(x1,lx[i]);
	for (int i=l;i<=mid;i++) y1=max(y1,ly[i]);
	for (int i=l;i<=mid;i++) x2=min(x2,rx[i]);
	for (int i=l;i<=mid;i++) y2=min(y2,ry[i]);
	cdq(mid+1,r);
}

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++)
		lx[i]=read(),
		ly[i]=read(),
		rx[i]=read(),
		ry[i]=read();
	cdq(1,n);
	
	return 0;
}