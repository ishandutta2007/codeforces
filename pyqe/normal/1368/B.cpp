#include <bits/stdc++.h>

using namespace std;

long long n,fq[10];
string ky="codeforces";

int main()
{
	long long i,j,z=1;
	
	scanf("%lld",&n);
	for(i=0;i<10;i++)
	{
		fq[i]=1;
	}
	for(i=0;z<n;i=(i+1)%10)
	{
		z/=fq[i];
		fq[i]++;
		z*=fq[i];
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<fq[i];j++)
		{
			printf("%c",ky[i]);
		}
	}
	printf("\n");
}