#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long a,b,ab;
	
	scanf("%lld%lld%lld",&a,&b,&ab);
	printf("%lld\n",ab*2+min(a,b)+min(max(a,b),min(a,b)+1));
}