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
int calc(int n){return n*(n+1)/2;}
void GreenDay()
{
	int k=read(),x=read();
	if (calc(k)+calc(k-1)<=x) print(2*k-1);
	else if (calc(k-1)>=x)
	{
		int l=1,r=k;
		while (l<=r)
		{
			int mid=(l+r)/2;
			if (calc(mid)<x) l=mid+1;
						else r=mid-1;
		}
		print(l);
	}
	else
	{
		x-=calc(k-1);
		int l=1,r=k;
		while (l<=r)
		{
			int mid=(l+r)/2;
			if (calc(k)-calc(k-mid)<x) l=mid+1;
								  else r=mid-1;
		}
		print(l+k-1);
	}
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
//	int T=1;
	int T=read();
	while (T--) GreenDay();
	
	return 0;
}