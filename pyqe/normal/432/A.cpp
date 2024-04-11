#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	long long n,k,i,l,c=0;
	
	scanf("%I64d%I64d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&l);
		if(5-l>=k)
		{
			c++;
		}
	}
	printf("%I64d\n",c/3);
}