#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[1000069],fw[2][1000069],fi;
pair<long long,long long> as[1000069];

void ud(long long xx,long long x,long long w)
{
	for(fi=x;fi<=n;fi+=fi&-fi)
	{
		fw[xx][fi]+=w;
	}
}

long long qr(long long xx,long long lh,long long rh)
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
	long long i,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&as[i].fr);
		as[i].sc=i;
	}
	sort(as+1,as+n+1);
	for(i=1;i<=n;i++)
	{
		a[as[i].sc]=i;
	}
	for(i=1;i<=n;i++)
	{
		z+=qr(1,a[i]+1,n);
		ud(1,a[i],qr(0,a[i]+1,n));
		ud(0,a[i],1);
	}
	printf("%lld\n",z);
}