#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<26> vtd;

int main()
{
	long long i,k;
	char ch;
	
	scanf("%lld",&n);
	if(n==1)
	{
		printf("Yes\n");
		return 0;
	}
	for(i=0;i<n;i++)
	{
		scanf(" %c",&ch);
		k=ch-'a';
		if(vtd[k])
		{
			printf("Yes\n");
			return 0;
		}
		vtd[k]=1;
	}
	printf("No\n");
}