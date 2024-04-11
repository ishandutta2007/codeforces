#include <bits/stdc++.h>

using namespace std;

long long n,a[169],d[169],dp[169],fq[26];

int main()
{
	long long t,rr,i,j,mx;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<26;i++)
		{
			fq[i]=0;
		}
		cin>>s;
		for(i=1;i<=n;i++)
		{
			a[i]=s[i-1]-'a';
			fq[a[i]]++;
		}
		cin>>s;
		for(i=1;i<=n;i++)
		{
			d[i]=s[i-1]-'a';
			fq[d[i]]--;
			dp[i]=0;
		}
		for(i=0;i<26;i++)
		{
			if(fq[i]!=0)
			{
				i=-1;
				break;
			}
		}
		if(i==-1)
		{
			printf("-1\n");
			continue;
		}
		mx=-1e18;
		for(i=1;i<=n;i++)
		{
			for(j=n;j>0;j--)
			{
				if(a[i]==d[j])
				{
					dp[j]=max(dp[j],dp[j-1]+1);
				}
				mx=max(mx,dp[j]);
			}
		}
		printf("%lld\n",n-mx);
	}
}