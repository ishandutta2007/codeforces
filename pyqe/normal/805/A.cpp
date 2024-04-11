#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

map<long long,long long> fq;

int main()
{
	long long i,j,k,l;
	pair<long long,long long> mxe={0,-1};
	
	scanf("%lld%lld",&k,&l);
	if(l-k+1>=4)
	{
		printf("2\n");
	}
	else
	{
		for(i=k;i<=l;i++)
		{
			for(j=1;j*j<=i;j++)
			{
				if(i%j==0)
				{
					if(j-1)
					{
						fq[j]++;
						mxe=max(mxe,{fq[j],j});
					}
					if(i/j!=j)
					{
						fq[i/j]++;
						mxe=max(mxe,{fq[i/j],i/j});
					}
				}
			}
		}
		printf("%lld\n",mxe.sc);
	}
}