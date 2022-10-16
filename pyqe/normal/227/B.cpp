#include <bits/stdc++.h>

using namespace std;

long long n,pst[100069];

int main()
{
	long long t,rr,i,k,z[2]={0,0};
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		pst[k]=i;
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		z[0]+=pst[k];
		z[1]+=n+1-pst[k];
	}
	printf("%lld %lld\n",z[0],z[1]);
}