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
#define mid (l+r)/2
int solve(int l,int r,int n,int f)
{
	if (l==r) return 1;
	if (n<l||r<n) return (r-l)*2+1;
	if (!f)
	{
		if (n<=mid) return solve(l,mid,n,1)+1;
		int ret=solve(l,mid,n,1)+1;
		return ret+solve(mid+1,r,n,0);
	}
	else
	{
		if (n>mid) return solve(mid+1,r,n,0)+1;
		int ret=solve(mid+1,r,n,0)+1;
		return ret+solve(l,mid,n,1);
	}
}
#undef mid
void GreenDay()
{
	int h=read(),n=read();
	print(solve(1,1LL<<h,n,0)-1);
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}