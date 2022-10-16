#include <bits/stdc++.h>

using namespace std;

map<long long,bool> vtd;
map<long long,long long> dsu,a;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		long long k=dsu[x];
		
		dsu[x]=fd(dsu[x]);
		a[x]^=a[k];
	}
	return dsu[x];
}

int main()
{
	long long t,rr,ky,k,l,w,tg,z,ls=0;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&ky,&k,&l);
		k^=ls;
		l^=ls;
		if(k>l)
		{
			swap(k,l);
		}
		k--;
		if(ky==1)
		{
			scanf("%lld",&w);
			w^=ls;
			if(!vtd[k]||!vtd[l]||fd(k)!=fd(l))
			{
				if(!vtd[k])
				{
					dsu[k]=k;
					vtd[k]=1;
				}
				if(!vtd[l])
				{
					dsu[l]=l;
					vtd[l]=1;
				}
				fd(k);
				tg=fd(l);
				a[tg]=w^a[k]^a[l];
				dsu[tg]=fd(k);
			}
		}
		else if(ky==2)
		{
			if(vtd[k]&&vtd[l]&&fd(k)==fd(l))
			{
				z=a[k]^a[l];
			}
			else
			{
				z=-1;
			}
			printf("%lld\n",z);
			ls=abs(z);
		}
	}
}