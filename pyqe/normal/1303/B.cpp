#include <bits/stdc++.h>

using namespace std;

long long n,nn;

int main()
{
	long long t,rr,k,l,w,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&k,&l);
		if(k>=l)
		{
			printf("%lld\n",n);
		}
		else
		{
			nn=(n+1)/2;
			w=(nn-1)/k;
			printf("%lld\n",max(w*(k+l)+nn-w*k,n));
		}
	}
}