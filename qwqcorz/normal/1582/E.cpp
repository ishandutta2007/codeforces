#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;

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
bool can[N],nxt[N];
ll a[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		int n=read(),ans=1;
		for (int i=1;i<=n;i++) a[i]=a[i-1]+read(),can[i]=1;
		for (int j=2,len=1;;len+=j++)
		{
			ll mx=0;
			memset(nxt,0,sizeof(bool)*(n+1));
			for (int i=n-len;i>=j;i--)
			{
				if (can[i+1]) mx=max(mx,a[i+j-1]-a[i]);
				if (mx>a[i]-a[i-j]) nxt[i-j+1]=1,ans=j;
			}
			memcpy(can,nxt,sizeof(bool)*(n+1));
			if (ans<j) break;
		}
		print(ans);
	}
	
	return 0;
}