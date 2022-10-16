#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,i,k,l,c=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&k,&l);
		if(k>l)
		{
			c++;
		}
		else if(k<l)
		{
			c--;
		}
	}
	if(c>0)
	{
		printf("Mishka\n");
	}
	else if(c<0)
	{
		printf("Chris\n");
	}
	else
	{
		printf("Friendship is magic!^^\n");
	}
}