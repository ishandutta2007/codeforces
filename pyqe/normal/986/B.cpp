#include <bits/stdc++.h>

using namespace std;

long long n,a[1000069],pst[1000069];

int main()
{
	long long i,k,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		pst[a[i]]=i;
	}
	for(i=1;i<=n;i++)
	{
		k=a[i];
		z+=k!=i;
		swap(a[pst[i]],a[i]);
		swap(pst[i],pst[k]);
	}
	if(z%2^n%2)
	{
		printf("Um_nik\n");
	}
	else
	{
		printf("Petr\n");
	}
}