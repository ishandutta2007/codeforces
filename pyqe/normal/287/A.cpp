#include <bits/stdc++.h>

using namespace std;

long long n=4;
bitset<1069> a[1069];

int main()
{
	long long i,j,ii,jj,sm;
	string s;
	
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=n;j++)
		{
			a[i][j]=s[j-1]=='#';
		}
	}
	for(i=1;i<=n-1;i++)
	{
		for(j=1;j<=n-1;j++)
		{
			sm=0;
			for(ii=i;ii<=i+1;ii++)
			{
				for(jj=j;jj<=j+1;jj++)
				{
					sm+=a[ii][jj];
				}
			}
			if(sm!=2)
			{
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
}