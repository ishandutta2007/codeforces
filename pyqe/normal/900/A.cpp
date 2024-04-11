#include <bits/stdc++.h>

using namespace std;

long long n,fq[2];

int main()
{
	long long i,x,y;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		fq[x<0]++;
	}
	if(min(fq[0],fq[1])<=1)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
}