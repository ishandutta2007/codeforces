#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long dv=1e9+7;
long long n,a[200069],ps[200069],ps2[200069],fw[2][200069],fi,sq[200069];
pair<long long,long long> as[200069],qq[200069],qs[200069];

inline void ud(long long xx,long long x,long long w)
{
	for(fi=x;fi<=n;fi+=fi&-fi)
	{
		fw[xx][fi]=(fw[xx][fi]+w)%dv;
	}
}

inline long long qr(long long xx,long long lh,long long rh)
{
	long long z=0;
	
	for(fi=rh;fi;fi-=fi&-fi)
	{
		z=(z+fw[xx][fi])%dv;
	}
	for(fi=lh-1;fi;fi-=fi&-fi)
	{
		z=(z+dv-fw[xx][fi])%dv;
	}
	return z;
}

int main()
{
	long long t,rr,i,k,l,w,pz,sm,c,sm2,c2;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		ps[i]=ps[i-1]+k;
		ps2[i]=(ps2[i-1]+(ps[i]%dv+dv)*(a[i+1]-a[i]))%dv;
		as[i]={ps[i],i};
	}
	sort(as+1,as+n+1);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		qq[rr]={k,l};
		qs[rr]={ps[k-1],rr};
	}
	sort(qs+1,qs+t+1);
	for(i=1,rr=1;rr<=t;rr++)
	{
		w=qs[rr].fr;
		pz=qs[rr].sc;
		for(;i<=n&&as[i].fr<=w;i++)
		{
			k=as[i].sc;
			ud(0,k,(ps[k]%dv+dv)*(a[k+1]-a[k])%dv);
			ud(1,k,a[k+1]-a[k]);
		}
		k=qq[pz].fr;
		l=qq[pz].sc;
		sm=qr(0,k,l);
		c=qr(1,k,l);
		sm2=(ps2[l]+dv-ps2[k-1]+dv-sm)%dv;
		c2=a[l+1]-a[k]-c;
		w=(w%dv+dv)%dv;
		sq[pz]=(w*c+dv-sm+sm2+dv-w*c2%dv)%dv;
	}
	for(rr=1;rr<=t;rr++)
	{
		printf("%lld\n",sq[rr]);
	}
}