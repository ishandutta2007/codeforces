#include <bits/stdc++.h>

using std::vector;

const int maxn = 66;
const int mod = 1e9+7;
int qpow(int x,int y)
{
	int ret=1;
	while(y)
	{
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return ret;
}

int n, a[maxn], c[maxn][maxn], f[maxn];
int gf(int x){return x==f[x]?x:f[x]=gf(f[x]);}

int tot, b[maxn], dp[maxn][1<<15], ways, num, have[1<<15];
void calc(vector<int> vs)
{
	tot=0;
	vector<int> qs;
	for(int i=0;i<vs.size();i++)
	{
		int cnt=0;
		for(int j=0;j<(int)vs.size();j++)if(vs[i]%vs[j]==0)cnt++;
		if(cnt==1)b[tot++]=vs[i];
		else qs.push_back(vs[i]);
	}
	if(qs.size() <= 1)
	{
		ways = 1;
		num = 0;
		return;
	}
	num = qs.size() - 1;
	for(int i=0;i<qs.size();i++)
	{
		int msk = 0;
		for(int j=0;j<tot;j++)
		{
			if(qs[i] % b[j] == 0)
				msk |= 1<<j;
		}
		qs[i] = msk;
	}
	
	memset(dp,0,sizeof(dp));
	memset(have,0,sizeof(have));
	for(int i=0;i<qs.size();i++)
	{
		dp[1][qs[i]] ++;
		have[qs[i]] ++;
	}
	for(int i=0;i<tot;i++)for(int j=0;j<(1<<tot);j++)if((j>>i)&1)have[j] += have[j^(1<<i)];
	
	for(int i=1;i<=(int)qs.size();i++)
	{
		for(int j=0;j<(1<<tot);j++)if(dp[i][j])
		{
			dp[i+1][j] = (dp[i+1][j] + 1ll*dp[i][j]*(have[j]-i))%mod;
			for(int k=0;k<(int)qs.size();k++) if((qs[k]&j) && (qs[k]&j)!=qs[k])
			{
				dp[i+1][j|qs[k]] += dp[i][j];
				if(dp[i+1][j|qs[k]] >= mod)
					dp[i+1][j|qs[k]] -=mod;
			}
		}
	}
	
	ways = dp[qs.size()][(1<<tot)-1];
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	std::sort(a+1,a+n+1);
	
	for(int i=0;i<maxn;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			c[i][j]=c[i-1][j]+c[i-1][j-1];
			if(c[i][j]>=mod)c[i][j]-=mod;
		}
	}
	
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(a[i]%a[j]==0)f[gf(i)]=gf(j);
	
	int ans1 = 1, ans2 = 0;
	for(int i=1;i<=n;i++)if(f[i]==i)
	{
		vector<int> vs;
		for(int j=1;j<=n;j++)if(gf(j)==i)vs.push_back(a[j]);
		calc(vs);
		ans1 = 1ll * ans1 * ways % mod * c[ans2 + num][num] %mod;
		ans2 += num;
	}
	printf("%d\n",ans1);
	return 0;
}