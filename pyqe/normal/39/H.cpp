#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,j,k,c,z;
	
	scanf("%lld",&n);
	for(i=1;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			for(c=0,z=0,k=i*j;k;z=z*10+k%n,k/=n,c++);
			for(k=z,z=0;c;z=z*10+k%10,k/=10,c--);
			printf("%lld%c",z," \n"[j==n-1]);
		}
	}
}