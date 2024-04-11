#include <bits/stdc++.h>

using namespace std;

long long n,a[2][3];

int main()
{
	long long ii,i,k,z[2]={0,0};
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<3;i++)
		{
			scanf("%lld",&a[ii][i]);
		}
	}
	for(i=0;i<3;i++)
	{
		k=a[0][i];
		for(ii=0;ii<2;ii++)
		{
			k-=min(a[0][i],a[1][(i+3-ii)%3]);
		}
		z[0]+=max(k,0ll);
		z[1]+=min(a[0][i],a[1][(i+1)%3]);
	}\
	printf("%lld %lld\n",z[0],z[1]);
}