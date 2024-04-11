#include <bits/stdc++.h>

using namespace std;

long long n[2],d,z[2];

int main()
{
	long long ii;
	
	scanf("%lld%lld%lld",n,n+1,&d);
	for(ii=0;ii<2;ii++)
	{
		n[ii]+=d;
		z[ii]=-(n[0]<n[1])+(n[0]>n[1]);
		n[ii]-=d;
	}
	if(z[0]!=z[1])
	{
		z[0]=2;
	}
	printf("%c\n","-0+?"[z[0]+1]);
}