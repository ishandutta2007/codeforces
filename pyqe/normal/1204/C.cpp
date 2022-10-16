#include <bits/stdc++.h>

using namespace std;

long long n,sp[169][169][169],m,a[1000069],dp[1000069];
vector<long long> pr[1000069];
bitset<1000069> vtd;

int main()
{
	long long i,j,r,sz,l,ll;
	string s;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=n;j++)
		{
			sp[0][i][j]=1e18;
			if(s[j-1]=='1')
			{
				sp[0][i][j]=1;
			}
		}
		sp[0][i][i]=0;
	}
	for(r=1;r<=n;r++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				sp[r][i][j]=min(sp[r-1][i][j],sp[r-1][i][r]+sp[r-1][r][j]);
			}
		}
	}
	scanf("%lld",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=m;j++)
		{
			if(i==1||sp[n][a[j-i]][a[j]]==i)
			{
				pr[j].push_back(j-i);
			}
		}
	}
	dp[1]=0;
	for(i=2;i<=m;i++)
	{
		dp[i]=0;
		sz=pr[i].size();
		for(j=0;j<sz;j++)
		{
			l=pr[i][j];
			dp[i]=max(dp[i],dp[l]+i-l-1);
		}
	}
	for(i=m;i>1;i=ll)
	{
		sz=pr[i].size();
		for(j=0;j<sz;j++)
		{
			l=pr[i][j];
			if(dp[i]==dp[l]+i-l-1)
			{
				ll=l;
				break;
			}
		}
		for(j=ll+1;j<=i-1;j++)
		{
			vtd[j]=1;
		}
	}
	printf("%lld\n",m-dp[m]);
	for(i=1;i<=m;i++)
	{
		if(vtd[i])
		{
			continue;
		}
		printf("%lld%c",a[i]," \n"[i==m]);
	}
}