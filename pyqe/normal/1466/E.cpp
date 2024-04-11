#include <bits/stdc++.h>

using namespace std;

long long n,a[500069],fq[60],dv=1e9+7;

int main()
{
	long long t,rr,i,j,k,w,ww,z=0;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<60;i++)
		{
			fq[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			for(j=0,k=a[i];k;k/=2,j++)
			{
				fq[j]+=k%2;
			}
		}
		z=0;
		for(i=1;i<=n;i++)
		{
			w=0;
			ww=0;
			for(j=0;j<60;j++)
			{
				if(a[i]>>j&1)
				{
					w=(w+(1ll<<j)%dv*fq[j])%dv;
					ww=(ww+(1ll<<j)%dv*n)%dv;
				}
				else
				{
					ww=(ww+(1ll<<j)%dv*fq[j])%dv;
				}
			}
			z=(z+w*ww)%dv;
		}
		printf("%lld\n",z);
	}
}