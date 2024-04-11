#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long k,ky[16]={1,0,0,1,0,1,0,1,1,1,0,0,1,0,1,0};
	
	scanf("%lld",&k);
	printf("%lld\n",ky[k-1]);
}