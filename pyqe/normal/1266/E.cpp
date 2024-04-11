#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[200069],fq[200069];
map<pair<long long,long long>,long long> ky;

int main()
{
	long long t,rr,i,k,l,w,tg,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		z+=a[i];
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		tg=ky[{k,l}];
		if(tg)
		{
			if(fq[tg]<=a[tg])
			{
				z++;
			}
			fq[tg]--;
		}
		if(w)
		{
			if(fq[w]<a[w])
			{
				z--;
			}
			fq[w]++;
		}
		ky[{k,l}]=w;
		printf("%lld\n",z);
	}
}