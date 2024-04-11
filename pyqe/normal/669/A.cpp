#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	scanf("%lld",&n);
	printf("%lld\n",n/3*2+!!(n%3));
}