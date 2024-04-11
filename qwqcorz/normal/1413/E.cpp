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
int a,b,c,d;
int check(int i)
{
	return i*a-b*d*(i-1)*i/2;
}

signed main()
{
	int T=read();
	while (T--)
	{
		a=read(),b=read(),c=read(),d=read();
		if (a-b*c>0) puts("-1");
//		else if (d>c) puts("0");
		else
		{
			int l=1,r=c/d+1;
			while (l<=r)
			{
				int mid1=l+(r-l+1)/3,mid2=l+(r-l+1)/3*2;
				if (check(mid1)<check(mid2)) l=mid1+1;
									    else r=mid2-1;
			}
			int ans=0;
			for (int i=max(l-5,1ll);i<=min(l+5,c/d+1);i++) ans=max(ans,check(i));
			print(ans);
		}
	}

	return 0;
}