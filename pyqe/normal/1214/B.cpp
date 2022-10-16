#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long k,l,w;
	
	scanf("%lld%lld%lld",&k,&l,&w);
	printf("%lld\n",min(k,w)-max(w-l,0ll)+1);
}