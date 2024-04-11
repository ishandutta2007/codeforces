#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,fq[100069],zs;
pair<long long,long long> sq[1000069];

void op(long long xx,long long nn)
{
	long long i,j,lh=nn+(1ll<<xx),rh;
	
	for(i=0;1ll<<i+1<=nn;i++);
	for(;i>=0;i--)
	{
		if(1ll<<i>lh-(1ll<<xx))
		{
			continue;
		}
		rh=lh-(1ll<<xx);
		lh=(1ll<<i)-(rh-(1ll<<i));
		if(lh<rh)
		{
			for(j=lh;j<1ll<<i;j+=1ll<<xx)
			{
				zs++;
				sq[zs]={j,(1ll<<i)+(1ll<<i)-j};
				fq[i+1]++;
			}
			op(xx+1,(1ll<<i)-lh<<1);
		}
		fq[i]++;
	}
}

int main()
{
	long long t,rr,i,e;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		if(n==2)
		{
			printf("-1\n");
			continue;
		}
		for(e=0;1ll<<e<=n-1;e++);
		zs=0;
		for(i=0;i<=e;i++)
		{
			fq[i]=0;
		}
		op(0,n);
		if(fq[0])
		{
			zs++;
			sq[zs]={1,1ll<<e-1};
			zs++;
			sq[zs]={(1ll<<e-1)-1,(1ll<<e-1)+1};
			fq[0]--;
			fq[e-1]--;
			fq[1]++;
			fq[e]++;
		}
		for(i=1;i<e;i++)
		{
			if(fq[i]%2)
			{
				zs++;
				sq[zs]={1ll<<i,1ll<<i};
				zs++;
				sq[zs]={0,1ll<<i};
				fq[i]--;
				fq[i+1]++;
			}
			for(;fq[i];)
			{
				zs++;
				sq[zs]={1ll<<i,1ll<<i};
				zs++;
				sq[zs]={0,1ll<<i+1};
				fq[i]-=2;
				fq[i+1]+=2;
			}
		}
		printf("%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			printf("%lld %lld\n",sq[i].fr,sq[i].sc);
		}
	}
}