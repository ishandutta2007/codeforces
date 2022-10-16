#include <bits/stdc++.h>

using namespace std;

long long n,fq[2][26],inf=1e18;

int main()
{
	long long i,j,ii,c;
	string s;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=n;j++)
		{
			fq[i==j||i+j==n+1][s[j-1]-'a']++;
		}
	}
	for(i=0;i<26;i++)
	{
		if(fq[0][i]&&fq[1][i])
		{
			printf("NO\n");
			return 0;
		}
	}
	for(ii=0;ii<2;ii++)
	{
		c=0;
		for(i=0;i<26;i++)
		{
			c+=!!fq[ii][i];
		}
		if(c>1)
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}