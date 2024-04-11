#include <bits/stdc++.h>

using namespace std;

long long n,pst[100069];

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		pst[k]=i;
	}
	printf("%lld\n",max(max(pst[1]-1,n-pst[1]),max(pst[n]-1,n-pst[n])));
}