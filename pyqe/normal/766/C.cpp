#include <bits/stdc++.h>

using namespace std;

long long n,a[1069],ub[26],dp[1069],nr[1069],dv=1e9+7,inf=1e18;

int main()
{
	long long i,j,mn,mx=-inf;
	string s;
	
	scanf("%lld",&n);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
	}
	for(i=0;i<26;i++)
	{
		scanf("%lld",ub+i);
	}
	dp[0]=1;
	for(i=1;i<=n;i++)
	{
		mn=inf;
		nr[i]=inf;
		for(j=i;j;j--)
		{
			mn=min(mn,ub[a[j]]);
			if(i-j+1>mn)
			{
				break;
			}
			dp[i]=(dp[i]+dp[j-1])%dv;
			nr[i]=min(nr[i],nr[j-1]+1);
		}
		mx=max(mx,i-j);
	}
	printf("%lld\n%lld\n%lld\n",dp[n],mx,nr[n]);
}