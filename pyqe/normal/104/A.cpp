#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	scanf("%lld",&n);
	n-=10;
	printf("%lld\n",4ll*(n>0&&n<=11)+11*(n==10));
}