#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long k,l;
	
	scanf("%lld%lld",&k,&l);
	if(k<l-1||(k+l)%2==0||(l<=1&&k))
	{
		printf("No\n");
	}
	else
	{
		printf("Yes\n");
	}
}