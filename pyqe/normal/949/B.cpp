#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,w;
	
	scanf("%lld%lld",&n,&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		for(w=n;1;k=w)
		{
			w-=k/2;
			if(k%2)
			{
				break;
			}
		}
		printf("%lld\n",n+1-w);
	}
}