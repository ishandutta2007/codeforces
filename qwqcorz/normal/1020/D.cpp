#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+7;

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
int Q(int x)
{
	printf("? %d\n",x);
	fflush(stdout);
	x=read();
	return x;
}
void A(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
	exit(0);
}

signed main()
{
	int n=read();
	int l=1,r=n/2+1,a=Q(1),c=Q(r),b=-inf,d=-inf;
	while (l<r)
	{
		int mid=(l+r)/2;
		b=Q(mid);
		d=Q(mid+n/2);
//		print(a,' ');
//		print(b,' ');
//		print(c,' ');
//		print(d,' ');
		if (a==c) A(l);
		if (b==d) A(mid);
		if ((a>c&&b<d)||(a<c&&b>d))
		{
			r=mid;
		}
		else
		{
			l=mid+1;
			a=b;
			c=d;
		}
	}
	A(-1);

	return 0;
}