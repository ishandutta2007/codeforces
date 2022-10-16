#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,sqn=316,a[100069],as[100069],fq[2000069],sq[100069];
pair<long long,long long> qq[100069];

bool mos(long long x,long long y)
{
	return mp(qq[x].fr/sqn,qq[x].sc)<mp(qq[y].fr/sqn,qq[y].sc);
}

int main()
{
	long long t,rr,i,ii,jj,u,uu,k,l,pz,lr[2],p[2]={0,1},z=0;
	
	scanf("%lld%lld%lld",&n,&t,&d);
	n++;
	for(i=2;i<=n;i++)
	{
		scanf("%lld",a+i);
		a[i]^=a[i-1];
	}
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		l++;
		qq[rr]={k,l};
		as[rr]=rr;
	}
	sort(as+1,as+t+1,mos);
	for(rr=1;rr<=t;rr++)
	{
		pz=as[rr];
		lr[0]=qq[pz].sc;
		lr[1]=qq[pz].fr;
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			for(jj=0;jj<2;jj++)
			{
				uu=!(ii^jj)*2-1;
				for(;p[jj]*uu<lr[jj]*uu;p[jj]+=uu)
				{
					z+=(fq[a[p[jj]+uu*!ii]^d]-(ii&&!d))*u;
					fq[a[p[jj]+uu*!ii]]+=u;
				}
			}
		}
		sq[pz]=z;
	}
	for(rr=1;rr<=t;rr++)
	{
		printf("%lld\n",sq[rr]);
	}
}