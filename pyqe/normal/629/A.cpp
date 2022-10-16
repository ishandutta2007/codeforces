#include <bits/stdc++.h>

using namespace std;

long long n,fq[2][1069];

int main()
{
	long long i,j,ii,k,z=0;
	string s;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=n;j++)
		{
			k=s[j-1]=='C';
			if(k)
			{
				for(ii=0;ii<2;ii++)
				{
					z+=fq[ii][i];
					fq[ii][i]++;
					swap(i,j);
				}
			}
		}
	}
	printf("%lld\n",z);
}