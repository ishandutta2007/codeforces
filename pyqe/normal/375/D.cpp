#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,sqn=316,aa[100069],a[100069],pst[100069],sbt[100069],qw[100069],fq[100069],sqa[100369],sqb[369],sq[100069];
vector<long long> al[100069];
bitset<100069> vtd;
pair<pair<long long,long long>,long long> qq[100069];

void bd(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	n++;
	a[n]=aa[x];
	pst[x]=n;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			bd(l);
			sbt[x]+=sbt[l];
		}
	}
}

bool sqs(pair<pair<long long,long long>,long long> x,pair<pair<long long,long long>,long long> y)
{
	if(x.fr.fr/sqn==y.fr.fr/sqn)
	{
		return x.fr.sc<y.fr.sc;
	}
	else
	{
		return x.fr.fr<y.fr.fr;
	}
}

void ud(long long x,long long w)
{
	sqa[x]+=w;
	sqb[x/sqn]+=w;
}

long long qr(long long lh,long long rh)
{
	long long i,sm=0;
	
	for(i=lh/sqn;i<=rh/sqn;i++)
	{
		sm+=sqb[i];
	}
	for(i=lh/sqn*sqn;i<lh;i++)
	{
		sm-=sqa[i];
	}
	for(i=rh+1;i<(rh/sqn+1)*sqn;i++)
	{
		sm-=sqa[i];
	}
	return sm;
}

int main()
{
	long long t,rr,i,ii,iii,u,uu,k,l,pz,lr[2],p[2]={0,0},e;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",aa+i);
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	n=0;
	bd(1);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",&k,qw+rr);
		qq[rr]={{pst[k],pst[k]+sbt[k]-1},rr};
	}
	sort(qq+1,qq+t+1,sqs);
	for(rr=1;rr<=t;rr++)
	{
		lr[0]=qq[rr].fr.fr-1;
		lr[1]=qq[rr].fr.sc;
		pz=qq[rr].sc;
		e=p[1]>=lr[0];
		for(ii=!e;ii!=e*3-1;ii+=e*2-1)
		{
			for(iii=0;iii<2;iii++)
			{
				u=iii*2-1;
				uu=(!ii^iii)*2-1;
				for(;p[ii]*u<lr[ii]*u;p[ii]+=u)
				{
					k=a[p[ii]+iii];
					ud(fq[k],-1);
					fq[k]+=uu;
					ud(fq[k],1);
				}
			}
		}
		sq[pz]=qr(qw[pz],n);
	}
	for(rr=1;rr<=t;rr++)
	{
		printf("%lld\n",sq[rr]);
	}
}