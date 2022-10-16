#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<200069> a,sq,fq;

int main()
{
	long long i,j,z=0;
	string s;
	
	scanf("%lld",&n);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'0';
	}
	for(i=1;i<=n;i++)
	{
		if(n%i==0)
		{
			for(j=0;j<i;j++)
			{
				fq[j]=0;
			}
			for(j=1;j<=n;j++)
			{
				fq[j%i]=fq[j%i]^a[j];
			}
			sq[i]=1;
			for(j=0;j<i;j++)
			{
				sq[i]=sq[i]&&!fq[j];
			}
			for(j=i+i;j<=n;j+=i)
			{
				sq[j]=sq[i];
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		z+=sq[i];
	}
	printf("%lld\n",z);
}