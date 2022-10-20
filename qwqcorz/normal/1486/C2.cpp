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
int get(int l,int r)
{
	printf("? %d %d\n",l,r);
	fflush(stdout);
	return read();
}

signed main()
{
	int n=read(),l=1,r=n,pos=get(1,n);
	if (pos==n||(pos>1&&get(1,pos)==pos))
	{
		r=pos;
		while (l+2<=r)
		{
			int mid=(l+r)/2;
			if (get(mid,pos)==pos) l=mid;
							  else r=mid-1;
		}
		if (l==r) printf("! %d\n",l);
			 else printf("! %d\n",l^r^get(l,r));
	}
	else
	{
		l=pos;
		while (l+2<=r)
		{
			int mid=(l+r)/2;
			if (get(pos,mid)==pos) r=mid;
							  else l=mid+1;
		}
		if (l==r) printf("! %d\n",l);
			 else printf("! %d\n",l^r^get(l,r));
	}

	return 0;
}