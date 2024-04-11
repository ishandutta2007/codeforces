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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
#define mk make_pair
map<pair<int,int>,int>a;
int get(int l,int r)
{
	if (a.count(mk(l,r))) return a[mk(l,r)];
	printf("? %d %d\n",l,r);
	fflush(stdout);
	return a[mk(l,r)]=read();
}

signed main()
{
	int n=read(),l=1,r=n;
	while (l+2<=r)
	{
		int mid=(l+r)/2;
		int x=get(l,r),y;
		if (x<=mid)
		{
			y=get(l,mid);
			if (x==y) r=mid;
				 else l=mid+1;
		}
		else
		{
			y=get(mid,r);
			if (x==y) l=mid;
				 else r=mid-1;
		}
	}
	if (l==r) printf("! %d\n",l);
		 else printf("! %d\n",l^r^get(l,r));

	return 0;
}