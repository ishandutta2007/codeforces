#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long y,x,y2,x2;
	
	scanf("%lld%lld%lld%lld",&y,&x,&y2,&x2);
	printf("%lld\n",max(abs(y-y2),abs(x-x2)));
}