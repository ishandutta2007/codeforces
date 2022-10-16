#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,pst[20],dp[300069][20],a[300069];

int main()
{
	long long i,t,rr,k,l,kk,j,jj;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		for(kk=a[i],j=0;j<20;j++,kk/=2)
		{
			if(kk%2)
			{
				for(jj=0;jj<20;jj++)
				{
					dp[i][jj]=max(dp[i][jj],dp[pst[j]][jj]);
				}
				dp[i][j]=i;
				pst[j]=i;
			}
		}
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		for(kk=a[k],j=0;j<20;j++,kk/=2)
		{
			if(kk%2&&k<=dp[l][j])
			{
				j=-1;
				break;
			}
		}
		if(j==-1)
		{
			printf("Shi\n");
		}
		else
		{
			printf("Fou\n");
		}
	}
}