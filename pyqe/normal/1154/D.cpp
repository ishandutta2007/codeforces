#include <bits/stdc++.h>

using namespace std;

long long n,d,d2,dd;

int main()
{
	long long i,k;
	
	scanf("%lld%lld%lld",&n,&d,&dd);
	d2=dd;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(!k)
		{
			if(d2)
			{
				d2--;
			}
			else if(d)
			{
				d--;
			}
			else
			{
				break;
			}
		}
		else
		{
			if(d2&&d2==dd)
			{
				d2--;
			}
			else if(d)
			{
				d--;
				d2++;
			}
			else if(d2)
			{
				d2--;
			}
			else
			{
				break;
			}
		}
	}
	printf("%lld\n",i);
}