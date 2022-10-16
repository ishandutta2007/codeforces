#include <bits/stdc++.h>

using namespace std;

long long n,d[2],ps[40069];

long long qr(long long x)
{
	return x/n*ps[n]+ps[x%n];
}

int main()
{
	long long tt,rrr,t,rr,i,ii,k,l;
	
	scanf("%lld",&tt);
	for(rrr=0;rrr<tt;rrr++)
	{
		scanf("%lld%lld%lld",d,d+1,&t);
		n=d[0]*d[1];
		for(i=1;i<=n;i++)
		{
			ps[i]=ps[i-1]+(i%d[0]%d[1]!=i%d[1]%d[0]);
		}
		for(rr=0;rr<t;rr++)
		{
			scanf("%lld%lld",&k,&l);
			printf("%lld%c",qr(l)-qr(k-1)," \n"[rr==t-1]);
		}
	}
}