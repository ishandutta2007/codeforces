#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d;
bitset<200069> a,spc;
pair<long long,long long> dp[200069];
string sq="BW";

int main()
{
	long long i,ii,iii,c,ls,k;
	string s;
	
	scanf("%lld%lld",&n,&d);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]=='W';
		dp[i]={1e18,0};
	}
	for(i=1;i<=n;i++)
	{
		spc[i]=a[(i+n-2)%n+1]==a[i]||a[i%n+1]==a[i];
	}
	for(iii=0;iii<2;iii++)
	{
		c=1e18;
		ls=0;
		for(ii=0;ii<2;ii++)
		{
			for(i=1+(n-1)*iii;i!=n+1-(n+1)*iii;i-=iii*2-1)
			{
				c++;
				if(spc[i])
				{
					c=0;
					ls=i;
				}
				dp[i]=min(dp[i],{c,ls});
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(dp[i].fr<=d)
		{
			k=a[dp[i].sc];
		}
		else
		{
			k=a[i]^d%2;
		}
		printf("%c",sq[k]);
	}
	printf("\n");
}