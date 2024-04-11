#include <bits/stdc++.h>

using namespace std;

long long n,d,mxn=1e5,mb[100069],fc[100069],ifc[100069],pwk,dv=1e9+7;
vector<long long> fz[100069];

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
	long long t,rr,i,j,k,sz,z;
	
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=mxn;i++)
	{
		mb[i]=1;
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	for(i=1;i<=mxn;i++)
	{
		if(mb[i])
		{
			sz=fz[i].size();
			for(j=i;j<=mxn;j+=i)
			{
				fz[j].push_back(i);
				if(sz==1)
				{
					mb[j]*=-!!(j%(i*i));
				}
			}
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		z=0;
		sz=fz[n].size();
		for(i=0;i<sz;i++)
		{
			k=fz[n][i];
			z=(z+cb(n/k-1,d-1)*(dv+mb[k]))%dv;
		}
		printf("%lld\n",z);
	}
}