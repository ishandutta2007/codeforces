#include <bits/stdc++.h>

long long d,d2,d3,d4,d5;

using namespace std;

int main()
{
	scanf("%lld%lld%lld%lld%lld",&d,&d2,&d3,&d4,&d5);
	printf("%lld\n",max(d3*2+d4-d,0ll)+max(d4+d5*3-d2,0ll));
}