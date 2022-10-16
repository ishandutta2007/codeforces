#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,a,b;
	
	scanf("%lld%lld%lld",&n,&a,&b);
	printf("%lld\n",min(n-a,b+1));
}