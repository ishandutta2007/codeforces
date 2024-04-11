#include <bits/stdc++.h>

using namespace std;

long long n,ps[100069],as[100069],fw[100069],fi;

inline void ud(long long x,long long w)
{
	for(fi=x;fi<=n-1;fi+=fi&-fi)
	{
		fw[fi]+=w;
	}
}

inline long long qr(long long lh,long long rh)
{
	long long sm=0;
	
	for(fi=rh;fi;fi-=fi&-fi)
	{
		sm+=fw[fi];
	}
	for(fi=lh-1;fi;fi-=fi&-fi)
	{
		sm-=fw[fi];
	}
	return sm;
}

int main()
{
	long long i,p,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",ps+i);
		ps[i]+=ps[i-1];
	}
	for(i=1;i<=n;i++)
	{
		if(ps[i]<0||ps[i]>ps[n])
		{
			printf("-1\n");
			return 0;
		}
	}
	for(i=1;i<n;i++)
	{
		as[i]=ps[i];
	}
	sort(as+1,as+n);
	for(i=1;i<n;i++)
	{
		p=lower_bound(as+1,as+n,ps[i])-as;
		z+=qr(p+1,n-1);
		ud(p,1);
	}
	printf("%lld\n",z);
}