#include <bits/stdc++.h>

using namespace std;

const long long ky[9]={1200,1400,1600,1900,2100,2300,2400,2600,3000};
long long n;

int main()
{
	scanf("%lld",&n);
	printf("%lld\n",*upper_bound(ky,ky+9,n));
}