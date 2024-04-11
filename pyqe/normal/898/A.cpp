#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	scanf("%lld",&n);
	printf("%lld\n",(n/10+(n%10>5))*10);
}