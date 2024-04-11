#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],fq[2];

int main()
{
	long long t,rr,i,ky,k;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[i]=k;
		fq[k]++;
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&ky,&k);
		if(ky==1)
		{
			fq[a[k]]--;
			a[k]=!a[k];
			fq[a[k]]++;
		}
		else
		{
			printf("%lld\n",(long long)(k<=fq[1]));
		}
	}
}