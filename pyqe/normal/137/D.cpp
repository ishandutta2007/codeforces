#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,a[569],sq[569],zs=0,inf=1e18;
pair<long long,long> dp[569][569];

int main()
{
	long long i,j,r,c,p,e;
	pair<long long,long long> z={inf,-1};
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
	}
	scanf("%lld",&d);
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=d;j++)
		{
			dp[i][j]={inf,-1};
		}
	}
	dp[0][0].fr=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			c=0;
			for(r=1;r<j+1-r;r++)
			{
				c+=a[i-j+r]!=a[i+1-r];
			}
			for(r=1;r<=d;r++)
			{
				dp[i][r]=min(dp[i][r],{dp[i-j][r-1].fr+c,i-j});
			}
		}
	}
	for(i=0;i<=d;i++)
	{
		z=min(z,{dp[n][i].fr,i});
	}
	e=z.sc;
	for(p=n;p;p=dp[p][e].sc,e--)
	{
		zs++;
		sq[zs]=p;
	}
	printf("%lld\n",z.fr);
	for(i=zs;i;i--)
	{
		for(j=1;j<=sq[i]-sq[i+1];j++)
		{
			a[sq[i+1]+j]=a[sq[i]+1-j];
			printf("%c",(char)a[sq[i+1]+j]+'a');
		}
		printf("%c","+\n"[i==1]);
	}
}