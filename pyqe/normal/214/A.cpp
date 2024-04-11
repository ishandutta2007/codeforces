#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,m,i,j,c=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i*i<=n;i++)
	{
		j=n-i*i;
		if(i+j*j==m)
		{
			c++;
		}
	}
	printf("%lld\n",c);
}