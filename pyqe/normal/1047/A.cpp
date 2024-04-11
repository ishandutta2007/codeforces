#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i;
	
	scanf("%lld",&n);
	for(i=0;i<3;i++)
	{
		printf("%lld%c",(n/3*3-3)*!i+1+(i<n%3)," \n"[i==2]);
	}
}