#include <bits/stdc++.h>

using namespace std;

long long n,lb,rb,d,m,sq[569];
bitset<569> vtd;

int main()
{
	long long t,rr,i,j,w,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&n,&lb,&rb,&d);
		m=rb-lb+1;
		d-=m*(m+1)/2;
		for(i=1;i<=n;i++)
		{
			vtd[i]=0;
		}
		for(i=m;i;i--)
		{
			w=min(n-m,max(d,0ll));
			sq[i]=i+w;
			d-=w;
			vtd[sq[i]]=1;
		}
		if(d)
		{
			printf("-1\n");
			continue;
		}
		for(j=1,i=1;i<=n;i++)
		{
			if(i<lb||i>rb)
			{
				for(;vtd[j];j++);
				z=j;
				vtd[j]=1;
			}
			else
			{
				z=sq[i-lb+1];
			}
			printf("%lld%c",z," \n"[i==n]);
		}
	}
}