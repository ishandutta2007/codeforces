#include <bits/stdc++.h>

using namespace std;

long long n,fq[26];

int main()
{
	long long i,k,z=0;
	char ch;
	
	scanf("%lld",&n);
	if(n>26)
	{
		printf("-1\n");
		return 0;
	}
	for(i=0;i<n;i++)
	{
		scanf(" %c",&ch);
		k=ch-'a';
		z+=!!fq[k];
		fq[k]++;
	}
	printf("%lld\n",z);
}