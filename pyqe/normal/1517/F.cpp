#include <bits/stdc++.h>

using namespace std;

const long long dv=998244353;
long long n,cr,dp[369][669],ps[2][669],tmp[669],pwk;
vector<long long> al[369];
bitset<369> vtd;

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

void dfs(long long x)
{
	long long i,j,ii,sz=al[x].size(),l;
	
	vtd[x]=1;
	for(i=0;i<=cr*2+1;i++)
	{
		dp[x][i]=0;
	}
	dp[x][0]=1;
	dp[x][cr+1]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			for(j=cr*2+1;j;j--)
			{
				dp[l][j]=dp[l][j-1];
			}
			dp[l][0]=0;
			for(ii=0;ii<2;ii++)
			{
				for(j=0;j<=cr*2+1;j++)
				{
					ps[ii][j+1]=(ps[ii][j]+dp[x][j])%dv;
				}
				swap(x,l);
			}
			for(j=0;j<=cr*2+1;j++)
			{
				tmp[j]=(dv-dp[x][j]*dp[l][j]%dv)%dv;
				for(ii=0;ii<2;ii++)
				{
					tmp[j]=(tmp[j]+dp[x][j]*(ps[!ii][max(cr*2+2-j,j+1)]+dv-ps[!ii][min(j,cr*2+2-j)]))%dv;
					swap(x,l);
				}
			}
			for(j=0;j<=cr*2+1;j++)
			{
				dp[x][j]=tmp[j];
			}
		}
	}
}

int main()
{
	long long i,j,k,l,sm,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	l=0;
	for(i=0;i<n;i++)
	{
		cr=i;
		vtd.reset();
		dfs(1);
		sm=0;
		for(j=0;j<=i;j++)
		{
			sm=(sm+dp[1][j])%dv;
		}
		z=(z+(sm+dv-l)*(i+dv-1))%dv;
		l=sm;
	}
	z=(z+n)%dv;
	z=z*pw(pw(2,n),dv-2)%dv;
	printf("%lld\n",z);
}