#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,sq[200069],inf=1e18;
pair<long long,long long> dp[200069][3];
string ky="RGB";

int main()
{
	long long i,j,r,k,e;
	pair<long long,long long> z={inf,-1};
	char ch;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		for(j=0;ky[j]!=ch;j++);
		k=j;
		for(j=0;j<3;j++)
		{
			dp[i][j]={inf,-1};
			for(r=1;r<3;r++)
			{
				dp[i][j]=min(dp[i][j],{dp[i-1][(j+r)%3].fr+(j!=k),(j+r)%3});
			}
		}
	}
	for(i=0;i<3;i++)
	{
		z=min(z,{dp[n][i].fr,i});
	}
	e=z.sc;
	for(i=n;i;i--)
	{
		sq[i]=e;
		e=dp[i][e].sc;
	}
	printf("%lld\n",z.fr);
	for(i=1;i<=n;i++)
	{
		printf("%c",ky[sq[i]]);
	}
	printf("\n");
}