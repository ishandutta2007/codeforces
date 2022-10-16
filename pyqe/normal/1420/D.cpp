#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,fc[300069],ifc[300069],pwk,dv=998244353;
pair<long long,long long> as[600069];

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

long long cb(long long x,long long y)
{
	if(x<y)
	{
		return 0;
	}
	return fc[x]*ifc[y]%dv*ifc[x-y]%dv;
}

int main()
{
	long long i,k,l,w,c=0,z=0;
	
	scanf("%lld%lld",&n,&d);
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=n;i++)
	{
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		as[i*2-1]={k,0};
		as[i*2]={l,1};
	}
	sort(as+1,as+n*2+1);
	for(i=1;i<=n*2;i++)
	{
		w=as[i].sc;
		if(!w)
		{
			z=(z+cb(c,d-1))%dv;
		}
		c+=!w*2-1;
	}
	printf("%lld\n",z);
}