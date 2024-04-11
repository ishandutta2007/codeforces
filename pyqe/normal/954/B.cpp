#include <bits/stdc++.h>

using namespace std;

long long n,a[1069];

int main()
{
	long long i,j;
	string s;
	
	scanf("%lld",&n);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
	}
	for(i=n/2;i+1;i--)
	{
		for(j=1;j<=i;j++)
		{
			if(a[j]!=a[j+i])
			{
				j=-1;
				break;
			}
		}
		if(j!=-1)
		{
			printf("%lld\n",i+!!i+n-i*2);
			return 0;
		}
	}
}