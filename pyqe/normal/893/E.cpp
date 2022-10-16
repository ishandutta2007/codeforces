#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,ma=1e6,fc[1000169],ifc[1000169],pwk,dv=1e9+7;
vector<pair<long long,long long>> fz[1000069];

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
	return fc[x]*ifc[y]%dv*ifc[x-y]%dv;
}

int main()
{
	long long t,rr,i,j,k,w,sz,z;
	
	for(i=2;i<=ma;i++)
	{
		if(!fz[i].size())
		{
			for(j=i;j<=ma;j+=i)
			{
				for(w=0,k=j;k%i==0;k/=i,w++);
				fz[j].push_back({i,w});
			}
		}
	}
	fc[0]=1;
	ifc[0]=1;
	for(i=1;i<=ma+100;i++)
	{
		fc[i]=fc[i-1]*i%dv;
		ifc[i]=pw(fc[i],dv-2);
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		z=pw(2,m-1);
		sz=fz[n].size();
		for(i=0;i<sz;i++)
		{
			w=fz[n][i].sc;
			z=z*cb(w+m-1,w)%dv;
		}
		printf("%lld\n",z);
	}
}