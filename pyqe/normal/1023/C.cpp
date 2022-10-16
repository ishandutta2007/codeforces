#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long i,u,c=0,sm=0;
	char ch;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n;i++)
	{
		scanf(" %c",&ch);
		u=(ch=='(')*2-1;
		if(sm+u>=0&&sm+u<=d-c-1)
		{
			c++;
			sm+=u;
			printf("%c",ch);
		}
	}
	printf("\n");
}