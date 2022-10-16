#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long i,j;
	char ch;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		a[i]=ch-'a';
		if(n%i==0)
		{
			for(j=1;j<i+1-j;j++)
			{
				swap(a[j],a[i+1-j]);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%c",(char)(a[i]+'a'));
	}
	printf("\n");
}