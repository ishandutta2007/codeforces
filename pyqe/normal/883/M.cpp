#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long y,x,y2,x2;
	
	scanf("%lld%lld%lld%lld",&y,&x,&y2,&x2);
	printf("%lld\n",(max(y,y2+1)-min(y,y2-1)+max(x,x2+1)-min(x,x2-1))*2);
}