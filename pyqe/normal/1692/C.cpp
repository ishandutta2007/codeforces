#include <bits/stdc++.h>

using namespace std;

const long long mm=8;
bitset<mm+1> a[mm+1];

int main()
{
	long long t,rr,i,j;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=1;i<=mm;i++)
		{
			for(j=1;j<=mm;j++)
			{
				scanf(" %c",&ch);
				a[i][j]=ch=='#';
			}
		}
		for(i=2;i<mm;i++)
		{
			for(j=2;j<mm;j++)
			{
				if(a[i][j]&&a[i-1][j-1]&&a[i-1][j+1]&&a[i+1][j-1]&&a[i+1][j+1])
				{
					printf("%lld %lld\n",i,j);
				}
			}
		}
	}
}