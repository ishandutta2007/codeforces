#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n[2],d[2],nn[2],sl[2][300069],wg[2][300069],sk[2][300069];

bool cmp(long long x,long long y,long long x2,long long y2)
{
	return mp(x/y,x%y*y2)<mp(x2/y2,x2%y2*y);
}

bool chk(long long ky,long long x,long long y,long long y2)
{
	long long u=!ky*2-1;
	
	return cmp(wg[ky][y2]-wg[ky][x],(sl[ky][x]-sl[ky][y2])*u,wg[ky][y]-wg[ky][x],(sl[ky][x]-sl[ky][y])*u);
}

long long f(long long ky,long long x,long long w)
{
	return sl[ky][x]*w+wg[ky][x];
}

int main()
{
	long long t,rr,ii,u,ky,k,l,lz=0,lz2=0,lh,rh,md,zz;
	pair<long long,long long> z;
	
	scanf("%lld%lld",d,&t);
	n[0]=1;
	nn[0]=1;
	sk[0][1]=1;
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&ky,&k);
		if(ky!=3)
		{
			ky=2-ky;
			u=!ky*2-1;
			n[ky]++;
			sl[ky][n[ky]]=(d[ky]+k*ky)*u;
			wg[ky][n[ky]]=-lz-lz2*(d[ky]+k*ky)*u;
			for(;nn[ky]>=2&&chk(ky,n[ky],sk[ky][nn[ky]],sk[ky][nn[ky]-1]);nn[ky]--);
			nn[ky]++;
			sk[ky][nn[ky]]=n[ky];
			d[ky]+=k;
		}
		else
		{
			scanf("%lld",&l);
			k+=l*d[1];
			lz+=k;
			lz2+=l;
		}
		z={inf,-1};
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			for(zz=1,lh=2,rh=nn[ii];lh<=rh;)
			{
				md=(lh+rh)/2;
				if(f(ii,sk[ii][md],lz2)<f(ii,sk[ii][md-1],lz2)+ii)
				{
					zz=sk[ii][md];
					lh=md+1;
				}
				else
				{
					rh=md-1;
				}
			}
			z=min(z,{f(ii,zz,lz2)+lz,sl[ii][zz]+d[1]+1});
		}
		printf("%lld %lld\n",z.sc,z.fr);
	}
}