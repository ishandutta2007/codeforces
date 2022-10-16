#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,nn=0,ln[4],dp[100069];
string ky[4]=
{
	"What are you doing at the end of the world? Are you busy? Will you save us?",
	"What are you doing while sending \"",
	"\"? Are you busy? Will you send \"",
	"\"?"
};

int main()
{
	long long t,rr,i,j,k,l,w;
	char z;
	
	for(i=0;i<4;i++)
	{
		ln[i]=ky[i].length();
	}
	dp[0]=ln[0];
	for(;1;)
	{
		nn++;
		dp[nn]=min(dp[nn-1]*2,inf+1);
		for(i=1;i<4;i++)
		{
			dp[nn]=min(dp[nn]+ln[i],inf+1);
		}
		if(dp[nn]>inf)
		{
			break;
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		if(l>dp[min(k,nn)])
		{
			printf(".");
			continue;
		}
		w=min((l-1)/ln[1],max(k-nn,0ll));
		k-=w;
		l-=w*ln[1];
		for(i=k;1;i--)
		{
			if(i)
			{
				for(j=1;j<4;j++)
				{
					if(l<=ln[j])
					{
						z=ky[j][l-1];
						j=-1;
						break;
					}
					l-=ln[j];
					if(l<=dp[i-1])
					{
						break;
					}
					l-=dp[i-1];
				}
				if(j==-1)
				{
					break;
				}
			}
			else
			{
				z=ky[0][l-1];
				break;
			}
		}
		printf("%c",z);
	}
	printf("\n");
}