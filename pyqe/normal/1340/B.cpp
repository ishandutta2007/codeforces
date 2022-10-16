#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,a[2069],ky[10],bp[10],tg[8],ans[2069][2069],as[2069],sq[2069],inf=1e18;
string ks[10];
pair<long long,long long> dp[2069][2069];

int main()
{
	long long i,j,r,k,w,e;
	string s;
	
	ks[0]={"1110111"};
	ks[1]={"0010010"};
	ks[2]={"1011101"};
	ks[3]={"1011011"};
	ks[4]={"0111010"};
	ks[5]={"1101011"};
	ks[6]={"1101111"};
	ks[7]={"1010010"};
	ks[8]={"1111111"};
	ks[9]={"1111011"};
	for(i=0;i<10;i++)
	{
		for(j=0;j<7;j++)
		{
			k=(ks[i][j]-'0');
			ky[i]|=k<<j;
			bp[i]+=k;
		}
	}
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=d;i++)
	{
		dp[0][i].fr=-1;
	}
	for(i=1;i<=n;i++)
	{
		cin>>s;
		w=0;
		for(j=0;j<7;j++)
		{
			k=(s[j]-'0');
			a[i]|=k<<j;
			w+=k;
		}
		for(j=0;j<=7;j++)
		{
			tg[j]=-1;
		}
		for(j=0;j<10;j++)
		{
			if((a[i]&ky[j])==a[i])
			{
				tg[bp[j]-w]=j;
			}
		}
		for(j=0;j<=d;j++)
		{
			dp[i][j]={-inf,-1};
			for(r=0;r<=min(7ll,j);r++)
			{
				if(tg[r]!=-1)
				{
					dp[i][j]=max(dp[i][j],{dp[i-1][j-r].fr*10+tg[r],r});
				}
			}
			k=dp[i][j].sc;
			if(k!=-1)
			{
				ans[i][j]=tg[k];
			}
			as[j]=dp[i][j].fr;
		}
		sort(as,as+d+1);
		for(j=0;j<=d;j++)
		{
			dp[i][j].fr=lower_bound(as,as+d+1,dp[i][j].fr)-as;
		}
	}
	e=d;
	for(i=n;i;i--)
	{
		sq[i]=ans[i][e];
		k=dp[i][e].sc;
		if(k==-1)
		{
			printf("-1\n");
			return 0;
		}
		e-=k;
	}
	if(e)
	{
		printf("-1\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld",sq[i]);
	}
	printf("\n");
}