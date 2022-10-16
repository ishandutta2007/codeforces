#include <bits/stdc++.h>

using namespace std;

long long n,ttl,a[1000069],wg[1000069],sq[1000069][2],z;

void ad(long long x,long long w)
{
	if(!w)
	{
		return;
	}
	w=min(a[(x+1)%n]-sq[x][1],w);
	z+=min(a[(x+1)%n]-sq[x][1]-sq[(x+1)%n][0],w);
	sq[x][1]+=w;
	w=max(sq[x][1]+sq[(x+1)%n][0]-a[(x+1)%n],0ll);
	sq[(x+1)%n][0]-=w;
	ad((x+1)%n,w);
}

int main()
{
	long long t,rr,i,ii,w;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		ttl=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",a+i);
			ttl+=a[i];
			for(ii=0;ii<2;ii++)
			{
				sq[i][ii]=0;
			}
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",wg+i);
		}
		z=0;
		for(i=0;i<n;i++)
		{
			w=min(a[i]-sq[(i+n-1)%n][1],wg[i]);
			sq[i][0]=w;
			z+=w;
			ad(i,wg[i]-w);
		}
		if(z==ttl)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}