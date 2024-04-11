#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,nm,nn,ln,p2[500069],ip2[500069],fq[500069],pr[500069],dp[500069],pwk,dv=998244353;
pair<pair<long long,long long>,long long> a[500069];
pair<long long,long long> as[500069],rg[500069];

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

int main()
{
	long long rr,i,j,k,l,w,ll,ww,sm,z=1;
	
	scanf("%lld%lld%lld",&n,&d,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		k--;
		a[i]={{k,l},w};
	}
	sort(a+1,a+m+1);
	p2[0]=1;
	ip2[0]=1;
	for(i=1;i<=n;i++)
	{
		p2[i]=p2[i-1]*2%dv;
		ip2[i]=pw(p2[i],dv-2);
	}
	for(rr=0;rr<d;rr++)
	{
		for(i=0;i<=n;i++)
		{
			fq[i]=0;
		}
		nm=0;
		for(i=1;i<=m;i++)
		{
			k=a[i].fr.fr;
			l=a[i].fr.sc;
			w=a[i].sc;
			if(w>>rr&1)
			{
				fq[k]++;
				fq[l]--;
			}
			else
			{
				nm++;
				as[nm]=a[i].fr;
			}
		}
		ln=0;
		sm=0;
		for(i=1;i<=n;i++)
		{
			sm+=fq[i-1];
			ln+=!sm;
			pr[i]=ln;
		}
		nn=0;
		for(i=1;i<=nm;i++)
		{
			as[i].fr=pr[as[i].fr];
			as[i].sc=pr[as[i].sc];
			l=as[i].sc;
			for(;nn&&rg[nn].sc>=l;nn--);
			nn++;
			rg[nn]=as[i];
		}
		sm=p2[ln];
		w=0;
		ww=0;
		for(j=0,i=1;i<=nn;i++)
		{
			k=rg[i].fr;
			l=rg[i].sc;
			for(;rg[j+1].sc<k;)
			{
				j++;
				ll=rg[j].sc;
				w=(w+dv-dp[j]*ip2[ln-ll]%dv)%dv;
				ww=(ww+dp[j])%dv;
			}
			dp[i]=(p2[ln-l+k]+dv-(w*p2[ln-l]+ww*ip2[l-k])%dv)%dv;
			w=(w+dp[i]*ip2[ln-l])%dv;
			sm=(sm+dv-dp[i])%dv;
		}
		z=z*sm%dv;
	}
	printf("%lld\n",z);
}