#include <bits/stdc++.h>

using namespace std;

long long n,sqn=224,z[224][224],a[500069];

int main()
{
	long long i,t,rr,ky,k,l,zzz;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&ky,&k,&l);
		if(ky==1)
		{
			a[k]+=l;
			for(i=1;i<sqn;i++)
			{
				z[i][k%i]+=l;
			}
		}
		else if(ky==2)
		{
			if(k<sqn)
			{
				printf("%lld\n",z[k][l]);
			}
			else
			{
				zzz=0;
				for(i=l;i<=500000;i+=k)
				{
					zzz+=a[i];
				}
				printf("%lld\n",zzz);
			}
		}
	}
}