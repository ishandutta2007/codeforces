#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,fw[2][200069],fi;
pair<long long,long long> a[100069],com[200069],rg[100069];
bitset<100069> kd;
pair<pair<long long,long long>,long long> as[200069];

bool cmp(pair<long long,long long> x,pair<long long,long long> y)
{
	return x.fr*y.sc<y.fr*x.sc;
}

inline void ud(long long xx,long long x,long long w)
{
	for(fi=x;fi<=n*2;fi+=fi&-fi)
	{
		fw[xx][fi]+=w;
	}
}

inline long long qr(long long xx,long long lh,long long rh)
{
	long long z=0;
	
	for(fi=rh;fi;fi-=fi&-fi)
	{
		z+=fw[xx][fi];
	}
	for(fi=lh-1;fi;fi-=fi&-fi)
	{
		z-=fw[xx][fi];
	}
	return z;
}

int main()
{
	long long i,k,l,p,e,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		kd[i]=k<0;
		k=abs(k);
		l=abs(l);
		a[i]={k,l};
		com[i*2-1]={k,l+d};
		com[i*2]={k,l-d};
	}
	sort(com+1,com+n*2+1,cmp);
	for(i=1;i<=n;i++)
	{
		k=a[i].fr;
		l=a[i].sc;
		rg[i].fr=lower_bound(com+1,com+n*2+1,mp(k,l+d),cmp)-com;
		rg[i].sc=lower_bound(com+1,com+n*2+1,mp(k,l-d),cmp)-com;
		k=rg[i].fr;
		l=rg[i].sc;
		as[i*2-1]={{k,-l},-i};
		as[i*2]={{l,0},i};
	}
	sort(as+1,as+n*2+1);
	for(i=1;i<=n*2;i++)
	{
		p=as[i].sc;
		e=p>0;
		p=abs(p);
		l=rg[p].sc;
		if(!e)
		{
			z+=qr(kd[p],l,n*2)+qr(!kd[p],1,n*2);
			ud(kd[p],l,1);
		}
		else
		{
			ud(kd[p],l,-1);
		}
	}
	printf("%lld\n",z);
}