#include <bits/stdc++.h>

using namespace std;

long long n,a[2][200069],sq[200069];

int main()
{
	long long i,ii,k;
	string s;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		cin>>s;
		for(i=1;i<=n;i++)
		{
			a[ii][i]=s[i-1]-'a';
		}
	}
	for(i=1;i<=n;i++)
	{
		k=a[0][i]+a[1][i];
		sq[i]+=k/2;
		sq[i+1]+=13*(k%2);
	}
	for(i=n;i;i--)
	{
		sq[i-1]+=sq[i]/26;
		sq[i]%=26;
	}
	for(i=1;i<=n;i++)
	{
		printf("%c",sq[i]+'a');
	}
	printf("\n");
}