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
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int mul(int x,int y)
{
	if (4e18/x<y) return 4e18;
	return x*y;
}
int check(int H,int n)
{
	int ret=H;
	n--;
	if (n&1) ret+=H+(n+1)/2;
	n/=2;
	return ret+2*min(mul(n,n+1)/2+mul(H,n),(int)4e18);
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read(),H=read();
	if (mul(H,H+1)/2>=n)
	{
		int l=1,r=H;
		while (l<=r)
		{
			int mid=(l+r)/2;
			if (mul(mid,mid+1)/2>=n) r=mid-1;
								else l=mid+1;
		}
		print(l);
	}
	else
	{
		n-=mul(H,H+1)/2;
		int l=1,r=1e18;
		while (l<=r)
		{
			int mid=(l+r)/2;
			if (check(H,mid)>=n) r=mid-1;
							else l=mid+1;
		}
		print(l+H);
	}
	
	return 0;
}