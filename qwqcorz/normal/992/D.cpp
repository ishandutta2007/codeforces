#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
const int Max=2e18;

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
int a[N],pre[N],sum[N];

signed main()
{
	pre[1]=0;
	int n=read(),k=read(),ans=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for (int i=2;i<=n;i++)
	if (a[i-1]==1) pre[i]=pre[i-1];
			  else pre[i]=i-1;
	for (int i=1;i<=n;i++)
	{
		int now=i,nxt,mul=1;
		while (now)
		{
			nxt=pre[now];
			if (mul>Max/a[now]) break;
			mul*=a[now];
			if (mul%k)
			{
				now=nxt;
				continue;
			}
			int need=sum[i]-mul/k;//sum[i]-sum[x-1]=a
			int pos=lower_bound(sum+nxt,sum+now,need)-sum;
			if (nxt<=pos&&pos<now&&sum[pos]==need) ans++;
			now=nxt;
		}
	}
	print(ans);

	return 0;
}