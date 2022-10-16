#include <bits/stdc++.h>

using namespace std;

int n,sqn=316,a[100069],dp[100069][369];

int main()
{
	int i,j,jj,t,rr,k,p,c;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	for(i=1;i<=min(n,sqn);i++)
	{
		for(j=n;j>0;j--)
		{
			jj=j+a[j]+i;
			if(jj>n)
			{
				dp[j][i]=1;
			}
			else
			{
				dp[j][i]=dp[jj][i]+1;
			}
		}
	}
	scanf("%d",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%d%d",&p,&k);
		if(k<=sqn)
		{
			printf("%d\n",dp[p][k]);
		}
		else
		{
			c=0;
			for(;p<=n;p+=a[p]+k,c++);
			printf("%d\n",c);
		}
	}
}