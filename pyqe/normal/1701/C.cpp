#include <bits/stdc++.h>

using namespace std;

long long n,m,fq[200069];

int main()
{
	long long t,rr,i,k,w,lh,rh,md,zz,c,c2;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			fq[i]=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld",&k);
			fq[k]++;
		}
		for(lh=0,rh=m*2;lh<=rh;)
		{
			md=(lh+rh)/2;
			c=0;
			c2=0;
			for(i=1;i<=n;i++)
			{
				w=min(md,fq[i]);
				c+=fq[i]-w;
				c2+=(md-w)/2;
			}
			if(c<=c2)
			{
				zz=md;
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		printf("%lld\n",zz);
	}
}