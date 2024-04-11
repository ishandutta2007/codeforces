#include <bits/stdc++.h>

using namespace std;

long long n,d,ttl,fq[1000069],sm[1000069],mn[1000069],inf=1e18;
bitset<1000069> a;

int main()
{
	long long t,rr,i,z;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		cin>>s;
		ttl=0;
		for(i=0;i<d;i++)
		{
			fq[i]=0;
			sm[i]=0;
			mn[i]=0;
		}
		for(i=0;i<n;i++)
		{
			a[i]=s[i]-'0';
			ttl+=a[i];
		}
		z=inf;
		for(i=0;i<n;i++)
		{
			fq[i%d]+=a[i];
			sm[i%d]+=a[i];
			mn[i%d]+=!a[i];
			mn[i%d]=min(mn[i%d],sm[i%d]);
			z=min(z,mn[i%d]+ttl-fq[i%d]);
		}
		printf("%lld\n",z);
	}
}