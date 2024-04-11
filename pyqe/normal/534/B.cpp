#include <bits/stdc++.h>

using namespace std;

long long n,d,st,fn;

long long tri(long long x)
{
	return x*(x+1)/2;
}

int main()
{
	long long i;
	
	scanf("%lld%lld%lld%lld",&st,&fn,&n,&d);
	for(i=1;i<n;i++)
	{
		if(abs(st+d*(i-1)-(fn+d*(n-i-1)))<=d)
		{
			printf("%lld\n",st*i+d*tri(i-1)+fn*(n-i)+d*tri(n-i-1));
			break;
		}
	}
}