#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,sqn=447,sqt=223,a[200069],pst[200069],udn=0,sq[50069],sqb[469];
pair<long long,long long> qq[50069],qs[469];
bitset<200469> vtd;

void sw(long long x,long long y)
{
	long long k=vtd[x];
	
	swap(a[x],a[y]);
	swap(pst[a[x]],pst[a[y]]);
	vtd[x]=vtd[y];
	vtd[y]=k;
}

void ud(long long x,long long w)
{
	vtd[x]=vtd[x]+w;
	sqb[x/sqn]+=w;
}

long long qr(long long lh,long long rh)
{
	long long i,z=0;
	
	for(i=lh/sqn;i<=rh/sqn;i++)
	{
		z+=sqb[i];
	}
	for(i=lh/sqn*sqn;i<lh;i++)
	{
		z-=vtd[i];
	}
	for(i=rh+1;i<(rh/sqn+1)*sqn;i++)
	{
		z-=vtd[i];
	}
	return z;
}

int main()
{
	long long t,rr,i,j,r,u,k,l,w,pz,ls,sm,kk,ll;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		a[i]=i;
		pst[i]=i;
	}
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		if(k>l)
		{
			swap(k,l);
		}
		udn++;
		qq[rr]={k,l};
		sw(k,l);
		qs[udn*2-1]={min(a[k],a[l]),rr};
		qs[udn*2]={max(a[k],a[l]),rr};
		if(udn==sqt||rr==t)
		{
			ls=(rr-1)/sqt*sqt;
			for(i=rr;i>ls;i--)
			{
				k=qq[i].fr;
				l=qq[i].sc;
				sw(k,l);
			}
			sort(qs+1,qs+udn*2+1);
			for(i=0;i<=n/sqn;i++)
			{
				sqb[i]=0;
			}
			vtd.reset();
			for(j=1,i=1;i<=udn*2;i++)
			{
				w=qs[i].fr;
				pz=qs[i].sc;
				k=qq[pz].fr;
				l=qq[pz].sc;
				for(;j<=w;j++)
				{
					ud(pst[j],1);
				}
				sm=qr(k+1,l-1);
				for(r=ls+1;r<=pz;r++)
				{
					kk=qq[r].fr;
					ll=qq[r].sc;
					sm-=vtd[kk]*(kk>k&&kk<l);
					sm-=vtd[ll]*(ll>k&&ll<l);
					sw(kk,ll);
					sm+=vtd[kk]*(kk>k&&kk<l);
					sm+=vtd[ll]*(ll>k&&ll<l);
				}
				for(r=pz;r>ls;r--)
				{
					kk=qq[r].fr;
					ll=qq[r].sc;
					sw(kk,ll);
				}
				sq[pz]=sm-sq[pz];
			}
			for(i=ls+1;i<=rr;i++)
			{
				k=qq[i].fr;
				l=qq[i].sc;
				sw(k,l);
			}
			udn=0;
		}
	}
	for(rr=t;rr;rr--)
	{
		k=qq[rr].fr;
		l=qq[rr].sc;
		sw(k,l);
	}
	for(rr=1;rr<=t;rr++)
	{
		k=qq[rr].fr;
		l=qq[rr].sc;
		sw(k,l);
		u=((a[k]>a[l])*2-1)*(a[k]!=a[l]);
		sq[rr]=sq[rr-1]+(sq[rr]*2+1)*u;
		printf("%lld\n",sq[rr]);
	}
}