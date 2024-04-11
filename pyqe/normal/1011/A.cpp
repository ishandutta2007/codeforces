#include <bits/stdc++.h>

using namespace std;

long long n,d;
bitset<26> fq;

int main()
{
	long long i,z=0;
	char ch;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n;i++)
	{
		scanf(" %c",&ch);
		fq[ch-'a']=1;
	}
	for(i=0;i<26&&d;i++)
	{
		if(fq[i])
		{
			z+=i+1;
			d--;
			i++;
		}
	}
	if(d)
	{
		z=-1;
	}
	printf("%lld\n",z);
}