#include <bits/stdc++.h>

using namespace std;

long long n,m,a[200069],d[200069],dp[2][200069];

int main()
{
	long long i,p,lh,rh,md,z=-1;
	string s;
	bool bad;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
	}
	cin>>s;
	m=s.length();
	for(i=1;i<=m;i++)
	{
		d[i]=s[i-1]-'a';
	}
	p=1;
	for(i=1;i<=n;i++)
	{
		if(p<=m&&a[i]==d[p])
		{
			p++;
		}
		dp[0][i]=p-1;
	}
	p=m;
	for(i=n;i>0;i--)
	{
		if(p>0&&a[i]==d[p])
		{
			p--;
		}
		dp[1][i]=m-p;
	}
	lh=0;
	rh=n;
	for(md=(lh+rh)/2;lh<=rh;md=(lh+rh)/2)
	{
		bad=1;
		for(i=md;i<=n;i++)
		{
			if(dp[0][i-md]+dp[1][i+1]>=m)
			{
				bad=0;
				break;
			}
		}
		if(bad)
		{
			rh=md-1;
		}
		else
		{
			z=md;
			lh=md+1;
		}
	}
	printf("%lld\n",z);
}