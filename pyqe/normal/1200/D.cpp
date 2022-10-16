#include <bits/stdc++.h>

using namespace std;

long long n,m,hz[2][2069][2],dp[2069][2069],z;
bool vtd[2069];
string s[2069];

int main()
{
	long long i,j,it,c=0,b=0;
	bool ft;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		cin>>s[i];
	}
	for(it=0;it<2;it++)
	{
		for(i=0;i<n;i++)
		{
			ft=1;
			for(j=0;j<n;j++)
			{
				if(it)
				{
					swap(i,j);
				}
				if(s[i][j]=='B')
				{
					if(it)
					{
						swap(i,j);
					}
					if(ft)
					{
						hz[it][i][0]=j;
						ft=0;
					}
					hz[it][i][1]=j;
					if(it)
					{
						swap(i,j);
					}
				}
				if(it)
				{
					swap(i,j);
				}
			}
			if(ft)
			{
				hz[it][i][0]=-1;
				hz[it][i][1]=-1;
				c++;
			}
		}
	}
	for(j=0;j<=n-m;j++)
	{
		z=0;
		for(i=0;i<n;i++)
		{
			if(hz[0][i][0]>=j&&hz[0][i][1]<=j+m-1)
			{
				vtd[i]=1;
			}
			else
			{
				vtd[i]=0;
			}
			z+=vtd[i];
			if(i>=m)
			{
				z-=vtd[i-m];
			}
			if(i>=m-1)
			{
				dp[i-m+1][j]+=z;
			}
		}
	}
	for(i=0;i<=n-m;i++)
	{
		z=0;
		for(j=0;j<n;j++)
		{
			if(hz[1][j][0]>=i&&hz[1][j][1]<=i+m-1)
			{
				vtd[j]=1;
			}
			else
			{
				vtd[j]=0;
			}
			z+=vtd[j];
			if(j>=m)
			{
				z-=vtd[j-m];
			}
			if(j>=m-1)
			{
				dp[i][j-m+1]+=z;
				b=max(b,dp[i][j-m+1]);
			}
		}
	}
	printf("%lld\n",b+c);
}