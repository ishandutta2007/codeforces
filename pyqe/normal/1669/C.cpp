#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<2> fq[2];

int main()
{
	long long t,rr,i,ii,jj,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			for(jj=0;jj<2;jj++)
			{
				fq[ii][jj]=0;
			}
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			fq[i%2][k%2]=1;
		}
		if(fq[0][0]+fq[0][1]<=1&&fq[1][0]+fq[1][1]<=1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}