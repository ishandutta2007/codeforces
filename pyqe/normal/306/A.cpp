#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long i;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		printf("%lld%c",n/m+(i<n%m)," \n"[i==m-1]);
	}
}