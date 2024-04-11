#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll read()
{
	ll s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
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
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
int cnt=0;
ll a[100],sum[100];

signed main()
{
	a[0]=0;
	for (int i=1;i<100;i++)
	{
		a[i]=a[i-1]*2+1;
		sum[i]=a[i]*(a[i]+1)/2+sum[i-1];
		cnt=i;
//		print(a[i],' ');
//		print(sum[i]);
		if (sum[i]>1e18) break;
	}
	int T=read();
	while (T--)
	{
		ll n=read();
		int ans=upper_bound(sum+1,sum+1+cnt,n)-sum-1;
		print(ans);
	}

	return 0;
}