#include<bits/stdc++.h>
#define int long long
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
int n,k;
int check(int x)
{
	return (1+x)*x/2-(n-x);
}

signed main()
{
	n=read();
	k=read();
	int l=0,r=n;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (check(mid)>=k) r=mid-1;
					  else l=mid+1;
	}
	print((1+l)*l/2-k);

	return 0;
}