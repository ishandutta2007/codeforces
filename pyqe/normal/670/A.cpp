#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long ii;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		n+=5*ii;
		printf("%lld%c",n/7*2+max(n%7-5,0ll)," \n"[ii]);
	}
}