#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,l,kk,ll;
	
	scanf("%lld",&n);
	for(k=0,l=1;max(k,l)<n;k=kk,l=ll)
	{
		kk=k+l+1;
		ll=k+k+1;
	}
	if(k==n||l==n)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}
}