#include <bits/stdc++.h>

using namespace std;

long long d[3]={5,2,1};

int main()
{
	long long t,rr,i,k,l,df,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		df=abs(k-l);
		z=0;
		for(i=0;i<3;i++)
		{
			z+=df/d[i];
			df%=d[i];
		}
		printf("%lld\n",z);
	}
}