#include <bits/stdc++.h>

using namespace std;

long long n,fq[2];

int main()
{
	long long t,rr,i,k,l,w;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		fq[k==1]++;
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		w=l-k+1;
		printf("%lld\n",(long long)(w%2==0&&min(fq[0],fq[1])>=w/2));
	}
}