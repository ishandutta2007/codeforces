#include<bits/stdc++.h>
#define int long long
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=2e5+5;
const int inf=2e10;

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
vector<pair<int,int>>dp[N],b[N];
int Min1[N],Min2[N],a[N];
void get(int i)
{
//	sort(dp[i].begin(),dp[i].end());
//	int n=dp[i].size();
//	Min1[i].resize(n);
//	Min2[i].resize(n);
//	for (int i=0;i<n;i++) Min1[i]=min(i?Min[i-1]:inf,dp[i].second+dp[i].first*2);
//	for (int i=n-1;i>=0;i--) Min2[i]=min(i<n-1?Min[i+1]:inf,dp[i].second+dp[i].first);
	Min1[i]=Min2[i]=inf;
	for (auto j:dp[i])
		Min1[i]=min(Min1[i],j.second+j.first),
		Min2[i]=min(Min2[i],j.second+j.first*2);
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int T=read();
	while (T--)
	{
		int n=read(),m=read();
		for (int i=1;i<=n;i++) a[i]=read();
		a[n+1]=1e9+7;
		sort(a+1,a+1+n);
		for (int i=1;i<=m;i++)
		{
			int l=read(),r=read();
			int pos=lower_bound(a+1,a+1+n,l)-a;
			if (a[pos]<=r) continue;
			b[pos-1].push_back(mk(l,r));
		}
		for (int i=1;i<=n;i++) sort(b[i].begin(),b[i].end());
		if (b[0].empty()) dp[0].push_back(mk(0,0));
		else
		{
			int mn=inf;
			for (auto i:b[0]) mn=min(mn,i.second);
			dp[0].push_back(mk(a[1]-mn,0));
		}
		get(0);
		for (int i=1;i<=n;i++)
		{
//			for (auto j:b[i]) print(j.first,','),print(j.second);
//			puts("");
			vector<int>suf(b[i].size()+1);
			for (int j=(int)b[i].size()-1;j>=0;j--)
			suf[j]=max(suf[j+1],a[i+1]-b[i][j].second);
			for (int j=0;j<=(int)b[i].size();j++)
			{
				int dis=j?b[i][j-1].first-a[i]:0;
				dp[i].push_back(mk(suf[j],min(Min1[i-1]+dis*2,Min2[i-1]+dis)));
			}
			get(i);
		}
		print(dp[n].back().second);
		for (int i=0;i<=n;i++) dp[i].clear(),b[i].clear();
//			Min1[i].clear(),
//			Min2[i].clear();
	}
	
	return 0;
}