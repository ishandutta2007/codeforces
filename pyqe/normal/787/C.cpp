#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn[2],al[2][7069],fq[2][7069],sq[2][7069];
bitset<7069> vtd[2];
queue<pair<long long,long long>> q;

int main()
{
	long long i,ii,kk,k,l,w;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		scanf("%lld",nn+ii);
		for(i=1;i<=nn[ii];i++)
		{
			scanf("%lld",&al[ii][i]);
		}
	}
	for(ii=0;ii<2;ii++)
	{
		q.push({ii,0});
		vtd[ii][0]=1;
	}
	for(;!q.empty();)
	{
		kk=q.front().fr;
		k=q.front().sc;
		w=sq[kk][k];
		q.pop();
		for(i=1;i<=nn[!kk];i++)
		{
			l=(k+n-al[!kk][i])%n;
			if(!vtd[!kk][l])
			{
				if(!w)
				{
					sq[!kk][l]=1;
					q.push({!kk,l});
					vtd[!kk][l]=1;
				}
				else
				{
					fq[!kk][l]++;
					if(fq[!kk][l]==nn[!kk])
					{
						q.push({!kk,l});
						vtd[!kk][l]=1;
					}
				}
			}
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<n;i++)
		{
			if(!vtd[ii][i])
			{
				printf("Loop");
			}
			else if(sq[ii][i])
			{
				printf("Win");
			}
			else
			{
				printf("Lose");
			}
			printf("%c"," \n"[i==n-1]);
		}
	}
}