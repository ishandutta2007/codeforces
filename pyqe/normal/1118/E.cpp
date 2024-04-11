#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long i,k,l;
	
	scanf("%lld%lld",&n,&d);
	if(d*(d-1)<n)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
		k=0;
		l=d;
		for(i=1;i<=n;i++)
		{
			if(i%2==1)
			{
				l++;
				if(l>d)
				{
					k++;
					l=k+1;
				}
			}
			printf("%lld %lld\n",k,l);
			swap(k,l);
		}
	}
}