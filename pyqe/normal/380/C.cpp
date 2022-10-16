#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,sk[1000069],fw[1000069],fwp,sq[100069];
pair<long long,long long> a[1000069];
pair<pair<long long,long long>,long long> qq[100069];

void ud(long long x,long long w)
{
	for(fwp=x;fwp<=n;fwp+=fwp&-fwp)
	{
		fw[fwp]+=w;
	}
}

long long qr(long long lh,long long rh)
{
	long long z=0;
	
	for(fwp=rh;fwp;fwp-=fwp&-fwp)
	{
		z+=fw[fwp];
	}
	for(fwp=lh-1;fwp;fwp-=fwp&-fwp)
	{
		z-=fw[fwp];
	}
	return z;
}

int main()
{
	long long t,rr,i,k,l,pz;
	string s;
	
	sk[0]=1e18;
	cin>>s;
	n=s.length();
	for(i=n;i;i--)
	{
		k=s[i-1]=='(';
		if(k)
		{
			a[i].fr=sk[nn];
			if(nn)
			{
				nn--;
			}
		}
		else
		{
			a[i].fr=1e18;
			nn++;
			sk[nn]=i;
		}
		a[i].sc=i;
	}
	sort(a+1,a+n+1);
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		qq[rr]={{l,k},rr};
	}
	sort(qq+1,qq+t+1);
	for(i=1,rr=1;rr<=t;rr++)
	{
		k=qq[rr].fr.sc;
		l=qq[rr].fr.fr;
		pz=qq[rr].sc;
		for(;i<=n&&a[i].fr<=l;i++)
		{
			ud(a[i].sc,1);
		}
		sq[pz]=qr(k,l)*2;
	}
	for(rr=1;rr<=t;rr++)
	{
		printf("%lld\n",sq[rr]);
	}
}