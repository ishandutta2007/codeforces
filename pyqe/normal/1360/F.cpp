#include <bits/stdc++.h>

using namespace std;

long long n,m,a[69][26],dp[69][1ll<<10],sq[69];

int main()
{
	long long t,rr,i,j,mk,mkk,e;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=m;i++)
		{
			for(j=0;j<26;j++)
			{
				a[i][j]=0;
			}
			for(mk=0;mk<1ll<<n;mk++)
			{
				dp[i][mk]=-1;
			}
		}
		for(i=0;i<n;i++)
		{
			cin>>s;
			for(j=1;j<=m;j++)
			{
				a[j][s[j-1]-'a']|=1ll<<i;
			}
		}
		dp[0][0]=0;
		for(i=1;i<=m;i++)
		{
			for(j=0;j<26;j++)
			{
				mkk=(1ll<<n)-1^a[i][j];
				for(mk=0;mk<1ll<<n;mk++)
				{
					if((mk&mkk)==mkk&&dp[i-1][mk^mkk]!=-1)
					{
						dp[i][mk]=j;
					}
				}
			}
		}
		e=-1;
		for(mk=0;mk<1ll<<n;mk++)
		{
			if(dp[m][mk]!=-1)
			{
				e=mk;
				break;
			}
		}
		if(e==-1)
		{
			printf("-1\n");
			continue;
		}
		for(i=m;i;i--)
		{
			sq[i]=dp[i][e];
			e^=(1ll<<n)-1^a[i][dp[i][e]];
		}
		for(i=1;i<=m;i++)
		{
			printf("%c",(char)sq[i]+'a');
		}
		printf("\n");
	}
}