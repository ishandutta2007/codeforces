#include <bits/stdc++.h>

using namespace std;

long long n,d,a[169],dp[169][169],sm[169];

int main()
{
	long long i,j,r,k,z=0;
	string s;
	
	scanf("%lld%lld",&n,&d);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
	}
	dp[0][0]=1;
	sm[0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(r=0;r<i;r++)
			{
				dp[i][j]+=dp[r][j-1];
				if(a[r]==a[i])
				{
					dp[i][j]-=dp[r][j];
				}
			}
			sm[j]+=dp[i][j];
		}
	}
	for(i=n;i>=0&&d;i--)
	{
		k=min(sm[i],d);
		d-=k;
		z+=(n-i)*k;
	}
	if(d)
	{
		printf("-1\n");
	}
	else
	{
		printf("%lld\n",z);
	}
}