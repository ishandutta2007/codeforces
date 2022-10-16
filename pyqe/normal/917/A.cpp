#include <bits/stdc++.h>

using namespace std;

long long n,a[5069],ls[2][5069];

int main()
{
	long long i,j,ii,u,sm,z=0;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		a[i]=(s[i-1]=='(')-(s[i-1]==')');
	}
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		for(i=1+(n-1)*ii;i&&i<=n;i+=u)
		{
			sm=0;
			for(j=i;j&&j<=n&&sm>=0;j+=u)
			{
				sm+=a[j]*u+!a[j];
			}
			ls[ii][i]=j-u;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j+=2)
		{
			z+=ls[0][i]>=j&&ls[1][j]<=i;
		}
	}
	printf("%lld\n",z);
}