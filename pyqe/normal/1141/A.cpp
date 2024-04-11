#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long x,y,k,c=0;
	
	scanf("%lld%lld",&x,&y);
	if(y%x!=0)
	{
		printf("-1\n");
		return 0;
	}
	k=y/x;
	for(;k%2==0;k/=2,c++);
	for(;k%3==0;k/=3,c++);
	if(k>1)
	{
		printf("-1\n");
		return 0;
	}
	printf("%lld\n",c);
}