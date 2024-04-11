#include <bits/stdc++.h>

using namespace std;

const long long dv=998244353;
long long n,d,nn=0,pst[100069],fc[100069],ifc[100069],pwk;

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

inline long long cb(long long x,long long y)
{
	return fc[x]*ifc[y]%dv*ifc[x-y]%dv;
}

int main()
{
	long long i,z=1;
	char ch;
	
	scanf("%lld%lld",&n,&d);
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		if(ch-'0')
		{
			nn++;
			pst[nn]=i;
		}
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	pst[nn+1]=n+1;
	if(d&&d<=nn)
	{
		for(i=1;i<=nn;i++)
		{
			z=(z+cb(pst[i+1]-1-pst[max(i-d,0ll)],min(d,i))+dv-cb(pst[i]-1-pst[max(i-d,0ll)],min(d,i)-1))%dv;
		}
	}
	printf("%lld\n",z);
}