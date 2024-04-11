#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int M=2e7+5;

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
ll dp[M],ans=0;
int a[N],tot[M];
bool vis[M],is[M];
vector<int>pr;
void ysgs(int n)
{
	for (int i=2;i<=n;i++)
	{
		if (!is[i]) pr.push_back(i);
		for (int j:pr)
		{
			if (j*i>n) break;
			is[j*i]=1;
			if (i%j==0) break;
		}
	}
}
void GreenDay()
{
	ysgs(2e7);
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)
	for (int j=1;j*j<=a[i];j++)
	if (a[i]%j==0)
	{
		tot[j]++;
		if (j*j<a[i]) tot[a[i]/j]++;
		vis[j]=vis[a[i]/j]=1;
	}
	dp[1]=n;
	for (int i=1;i<M;i++)
	{
		ans=max(ans,dp[i]);
		if (vis[i]) for (int j:pr)
		{
			if (i*j>=M) break;
			dp[i*j]=max(dp[i*j],dp[i]+1LL*tot[i*j]*(i*j-i));
		}
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