#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long a,b,c;
	
	scanf("%lld%lld%lld",&a,&b,&c);
	printf("%lld\n",min(a+1,min(b,c-1))*3);
}