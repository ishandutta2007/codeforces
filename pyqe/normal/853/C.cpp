#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,fw[200069],fi,la[1600069],ra[1600069],sq[200069];
pair<long long,long long> a[200069],qq[1600069];
bitset<1600069> iv,ua;

void ud(long long x,long long w)
{
	for(fi=x;fi<=n;fi+=fi&-fi)
	{
		fw[fi]+=w;
	}
}

long long qr(long long lh,long long rh)
{
	long long z=0;
	
	for(fi=rh;fi;fi-=fi&-fi)
	{
		z+=fw[fi];
	}
	for(fi=lh-1;fi;fi-=fi&-fi)
	{
		z-=fw[fi];
	}
	return z;
}

void ad(long long db,long long lb,long long rb,bool e,bool u)
{
	qq[nn]={db,nn};
	la[nn]=lb;
	ra[nn]=rb;
	iv[nn]=e;
	ua[nn]=u;
	nn++;
}

int main()
{
	long long t,rr,i,k,w,lb,rb,db,ub,pz,u;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[i]={k,i};
	}
	sort(a+1,a+n+1);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&lb,&db,&rb,&ub);
		sq[rr]=n*(n-1)/2;
		ad(db-1,1,n,0,0);
		ad(db-1,1,lb-1,0,1);
		ad(db-1,rb+1,n,0,1);
		ad(n,1,lb-1,0,0);
		ad(n,rb+1,n,0,0);
		ad(ub,1,n,1,0);
		ad(ub,1,lb-1,1,1);
		ad(ub,rb+1,n,1,1);
	}
	sort(qq,qq+nn);
	for(i=1,rr=0;rr<nn;rr++)
	{
		w=qq[rr].fr;
		pz=qq[rr].sc;
		for(;i<=n&&a[i].fr<=w;i++)
		{
			k=a[i].sc;
			ud(k,1);
		}
		u=ua[pz]*2-1;
		w=qr(la[pz],ra[pz]);
		if(iv[pz])
		{
			w=ra[pz]-la[pz]+1-w;
		}
		sq[pz/8]+=w*(w-1)/2*u;
	}
	for(rr=0;rr<t;rr++)
	{
		printf("%lld\n",sq[rr]);
	}
}