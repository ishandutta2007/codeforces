#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long k,l;
	
	scanf("%lld%lld",&k,&l);
	printf("%lld\n",abs(k-l)/2*(abs(k-l)/2+1)/2+(abs(k-l)+1)/2*((abs(k-l)+1)/2+1)/2);
}