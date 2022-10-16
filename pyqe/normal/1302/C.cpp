#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	scanf("%lld%lld",&n,&m);
	m=n-m;
	printf("%lld\n",min(m,n-m+(m==n)));
}