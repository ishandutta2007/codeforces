#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,dsu[4069],cc[4069],dp[4069][4069],tmp[4069];
pair<long long,long long> a[4069];

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	long long i,j,r,u,k,l,w,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[i]={k,i};
	}
	sort(a+1,a+n+1,greater<pair<long long,long long>>());
	for(i=1;i<=n;i++)
	{
		w=a[i].fr;
		k=a[i].sc;
		dsu[k]=k;
		cc[k]=1;
		dp[k][1]=w*m-w;
		for(u=-1;u<=1;u+=2)
		{
			if(dsu[k+u])
			{
				l=fd(k+u);
				for(j=0;j<=cc[k];j++)
				{
					for(r=0;r<=cc[l];r++)
					{
						tmp[j+r]=max(tmp[j+r],dp[k][j]+dp[l][r]-w*j*r*2);
					}
				}
				cc[k]+=cc[l];
				dsu[l]=k;
				for(j=0;j<=cc[k];j++)
				{
					dp[k][j]=tmp[j];
					tmp[j]=0;
				}
			}
		}
		z=max(z,dp[k][m]);
	}
	printf("%lld\n",z);
}