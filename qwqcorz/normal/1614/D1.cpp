#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e6+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x,char c='\n')
{
	write(x);
	putchar(c);
}
ll dp[N],ans=0;
int a[N],tot[N];
void GreenDay()
{
	int n=read();
	for (int i=1;i<=n;i++) a[read()]++;
	for (int i=1;i<N;i++)
	for (int j=i;j<N;j+=i) tot[i]+=a[j];
	dp[1]=n;
	for (int i=1;i<N;i++)
	{
		ans=max(ans,dp[i]);
		for (int j=i+i;j<N;j+=i) dp[j]=max(dp[j],dp[i]+1LL*tot[j]*(j-i));
	}
	print(ans);
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}