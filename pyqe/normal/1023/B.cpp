#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	scanf("%lld%lld",&n,&d);
	printf("%lld\n",min((d-1)/2,max(n-d/2,0ll)));
}