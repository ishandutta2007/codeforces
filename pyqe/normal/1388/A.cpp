#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		if(n<=30)
		{
			printf("NO\n");
		}
		else
		{
			k=n-30;
			l=14;
			if(k==6||k==10||k==14)
			{
				k--;
				l++;
			}
			printf("YES\n6 10 %lld %lld\n",l,k);
		}
	}
}