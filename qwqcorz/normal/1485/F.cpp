#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
const int p=1e9+7;

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
int add(int &x,int y)
{
	x+=y;
	if (x>=p) x-=p;
	return x;
}
int a[N];
ll sum[N];
map<ll,int>mp;

signed main()
{
	int T=read();
	while (T--)
	{
		mp.clear();
		int n=read(),ans=1;
		for (int i=1;i<=n;i++) a[i]=read();
		for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
		mp[0]=1;
		for (int i=1;i<=n;i++)
		{
			int tmp=(ans-(mp[sum[i]-a[i]])+p)%p;
			add(ans,tmp);
			add(mp[sum[i-1]],tmp);
		}
		print(ans);
	}

	return 0;
}