#include <bits/stdc++.h>

using namespace std;

long long n,ls[2][1069];

int main()
{
	long long i,j,ii,k,ti,tj;
	string s;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=n;j++)
		{
			k=s[j-1]=='E';
			if(!k)
			{
				for(ii=0;ii<2;ii++)
				{
					ls[ii][i]=j;
					swap(i,j);
				}
			}
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			if(!ls[ii][i])
			{
				i=-1;
				break;
			}
		}
		if(i!=-1)
		{
			for(i=1;i<=n;i++)
			{
				ti=i;
				tj=ls[ii][i];
				if(ii)
				{
					swap(ti,tj);
				}
				printf("%lld %lld\n",ti,tj);
			}
			return 0;
		}
	}
	printf("-1\n");
}