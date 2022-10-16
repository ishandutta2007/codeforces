#include <bits/stdc++.h>

using namespace std;

long long n,m,a[200069],al[200069],ls[200069],pr[200069][18],bl[200069],an[200069],dp[200069];
bitset<200069> sq;

int main()
{
	long long t,rr,i,j,k,l,p;
	
	scanf("%lld%lld%lld",&n,&m,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		if(i>1)
		{
			al[a[i]]=a[i-1];
		}
	}
	al[a[1]]=a[n];
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&k);
		if(ls[al[k]])
		{
			pr[i][0]=ls[al[k]];
			for(j=1;j-1<bl[pr[i][j-1]];j++)
			{
				pr[i][j]=pr[pr[i][j-1]][j-1];
			}
			bl[i]=j;
		}
		p=i;
		for(j=17;j>=0;j--)
		{
			if((n-1)&(1<<j))
			{
				if(j<bl[p])
				{
					p=pr[p][j];
				}
				else
				{
					j=-69;
					break;
				}
			}
		}
		if(j!=-69)
		{
			an[i]=p;
		}
		dp[i]=max(dp[i-1],an[i]);
		ls[k]=i;
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		sq[rr]=dp[l]>=k;
	}
	for(i=0;i<t;i++)
	{
		printf("%d",(bool)sq[i]);
	}
	printf("\n");
}