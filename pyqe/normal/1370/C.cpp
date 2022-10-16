#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(k=n;k%2==0;k/=2);
		for(i=2;i*i<=n;i++)
		{
			if(k%i==0)
			{
				i=-1;
				break;
			}
		}
		if(k==1)
		{
			i=-1;
		}
		if(n>1&&(n%2||k>1||n==2)&&!(n/k==2&&i!=-1))
		{
			printf("Ashishgup\n");
		}
		else
		{
			printf("FastestFinger\n");
		}
	}
}