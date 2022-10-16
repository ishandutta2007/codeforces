#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,ds,dd,d,nn=0,cp[100069],ps[100069],inf=1e18;
pair<long long,long long> as[100069];

int main()
{
	long long i,ii,k,w,p,lh,rh,md,zz,mn,e,c,sm;
	pair<long long,long long> mne={inf,0},z={-inf,-inf};
	
	scanf("%lld%lld%lld",&n,&ds,&dd);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",cp+i,&k,&w);
		if(w>=ds)
		{
			nn++;
			as[nn]={k,i};
			if(cp[i])
			{
				mne=min(mne,{k,i});
			}
		}
	}
	sort(cp+1,cp+n+1,greater<long long>());
	sort(as+1,as+nn+1);
	mn=mne.fr;
	e=mne.sc;
	for(i=1;i<=n;i++)
	{
		ps[i]=ps[i-1]+cp[i];
	}
	zz=n;
	for(lh=1,rh=n;lh<=rh;)
	{
		md=(lh+rh)/2;
		if(ps[md]-md<0)
		{
			zz=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	for(ii=0;ii<=(e&&mn<=dd);ii++)
	{
		c=zz*ii;
		sm=mn*ii;
		d=dd-mn*ii;
		for(i=1;i<=nn&&c<n;i++)
		{
			k=as[i].fr;
			p=as[i].sc;
			if((!ii||p!=e)&&k<=d)
			{
				c++;
				sm+=k;
				d-=k;
			}
		}
		z=max(z,{c,-sm});
	}
	printf("%lld %lld\n",z.fr,-z.sc);
}