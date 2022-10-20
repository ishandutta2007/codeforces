#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int p=998244353;

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
struct node
{
	int l,r,x;
	bool operator <(const node &a)const
	{
		return r<a.r;
	}
}b[N];
pair<int,int>a[N];
int c[N],dp[N],sum[N];

signed main(signed bangumi,char *ss1672[])
{
	(void)bangumi,(void)ss1672;
	int n=read(),k=read(),m=read(),ans=1;
	for (int i=1;i<=m;i++)
		b[i].l=read(),
		b[i].r=read(),
		b[i].x=read();
	sort(b+1,b+1+m);
	for (int j=0;j<k;j++)
	{
		for (int i=1;i<=n;i++) c[i]=0;
		int cnt=0;
		for (int i=1;i<=m;i++)
		if (b[i].x>>j&1)
			c[b[i].l]++,
			c[b[i].r+1]--;
		else
			a[++cnt]=make_pair(b[i].l,b[i].r);
		for (int i=1;i<=n+1;i++) c[i]+=c[i-1];
		sum[0]=!c[1]*(dp[0]=1);
		for (int i=1,j=1,mx=0;i<=n;i++)
		{
			while (j<=cnt&&a[j].second<=i) mx=max(mx,a[j++].first);
			dp[i]=(sum[i-1]-(mx>=2?sum[mx-2]:0)+p+!mx)%p;
			sum[i]=(sum[i-1]+!c[i+1]*dp[i])%p;
		}
		ans=1LL*ans*dp[n]%p;
	}
	print(ans);
	
	return 0;
}