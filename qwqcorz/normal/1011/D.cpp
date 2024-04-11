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
int Q(int x)
{
	print(x);
	fflush(stdout);
	int ans=read();
	if (ans==0) exit(0);
	return ans;
}
int a[66];

signed main()
{
	int m=read(),n=read();
	for (int i=1;i<=n;i++) a[i]=Q(1);
	int l=1,r=m,i=0;
	while (l<=r)
	{
		i++;
		if (i>n) i=1;
		int mid=(l+r)/2;
		if (Q(mid)*a[i]>0) l=mid+1;
					  else r=mid-1;
	}

	return 0;
}