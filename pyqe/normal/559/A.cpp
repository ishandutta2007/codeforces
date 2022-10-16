#include <bits/stdc++.h>

using namespace std;

long long a[6];

int main()
{
	long long i,w=0,z=0;
	
	for(i=0;i<6;i++)
	{
		scanf("%lld",a+i);
		w+=a[i]*(i<3);
		z-=a[i]*a[i]*(i%2==0);
	}
	z+=w*w;
	printf("%lld\n",z);
}