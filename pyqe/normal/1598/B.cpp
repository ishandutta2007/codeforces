#include <bits/stdc++.h>

using namespace std;

const long long d=5;
long long n;
bitset<5> a[100069];

int main()
{
	long long t,rr,i,j,r,k,c[4],mk;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			for(j=0;j<d;j++)
			{
				scanf("%lld",&k);
				a[i][j]=k;
			}
		}
		for(i=0;i<d;i++)
		{
			for(j=i+1;j<d;j++)
			{
				for(mk=0;mk<4;mk++)
				{
					c[mk]=0;
				}
				for(r=1;r<=n;r++)
				{
					mk=(long long)a[r][i]<<1|a[r][j];
					c[mk]++;
				}
				if(!c[0]&&min(c[1]+c[3],c[2]+c[3])>=n/2)
				{
					break;
				}
			}
			if(j<d)
			{
				break;
			}
		}
		if(i<d)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}