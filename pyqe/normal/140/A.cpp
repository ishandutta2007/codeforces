#include <bits/stdc++.h>

using namespace std;

long long n,m,d;
double pi=3.14159265358979323846;

int main()
{
	long long i;
	double agl;
	
	scanf("%lld%lld%lld",&d,&n,&m);
	if(m>n)
	{
		if(d)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
	else if(m*2>n)
	{
		if(d>1)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
	else
	{
		agl=asin((double)m/(n-m))*2;
		if(agl*d>pi*2+1e-9)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
}