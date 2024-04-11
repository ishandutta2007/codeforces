#include <bits/stdc++.h>

using namespace std;

long long n,ma=1e3,yk[1069],sq[1069],zs;

int main()
{
	long long t,rr,i,j,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i*i<=ma;i++)
		{
			yk[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			sq[i]=k;
			for(j=2;j*j<=k;j++)
			{
				if(k%j==0)
				{
					sq[i]=j;
					break;
				}
			}
			yk[sq[i]]=1;
		}
		zs=0;
		for(i=1;i*i<=ma;i++)
		{
			zs+=yk[i];
			yk[i]=zs;
		}
		printf("%lld\n",zs);
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",yk[sq[i]]," \n"[i==n]);
		}
	}
}