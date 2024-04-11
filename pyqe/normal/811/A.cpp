#include <bits/stdc++.h>

using namespace std;

long long n[2];

int main()
{
	long long i;
	
	scanf("%lld%lld",n,n+1);
	for(i=1;1;i++)
	{
		if(n[(i+1)%2]<i)
		{
			break;
		}
		n[(i+1)%2]-=i;
	}
	if(i%2)
	{
		printf("Vladik\n");
	}
	else
	{
		printf("Valera\n");
	}
}