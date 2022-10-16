#include <bits/stdc++.h>

using namespace std;

long long n,fq[2];

int main()
{
	long long i;
	char ch;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf(" %c",&ch);
		fq[ch-'0']++;
	}
	if(fq[1])
	{
		printf("1");
	}
	for(i=0;i<fq[0];i++)
	{
		printf("0");
	}
	printf("\n");
}