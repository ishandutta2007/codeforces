#include <bits/stdc++.h>

using namespace std;

long long n,m,a[100069];

int main()
{
	long long i,j,k,z;
	string s;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		cin>>s;
		if(!i)
		{
			m=s.length();
			for(j=1;j<=m;j++)
			{
				a[j]=-1;
			}
		}
		for(j=1;j<=m;j++)
		{
			k=s[j-1]-'0';
			if(a[j]==-1||k==a[j])
			{
				a[j]=k;
			}
			else
			{
				a[j]=-2;
			}
		}
	}
	for(z=0;a[z+1]!=-2;z++);
	printf("%lld\n",z);
}