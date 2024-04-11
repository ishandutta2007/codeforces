#include <bits/stdc++.h>

using namespace std;

long long n,a[169];

int main()
{
	long long i,j,c=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a,a+n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[i]%a[j]==0)
			{
				j=-1;
				break;
			}
		}
		if(j!=-1)
		{
			c++;
		}
	}
	printf("%lld\n",c);
}