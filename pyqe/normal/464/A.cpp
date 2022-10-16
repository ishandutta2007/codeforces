#include <bits/stdc++.h>

using namespace std;

long long n,d,a[1069];

bool bf(long long x)
{
	for(a[x]++;1;a[x]++)
	{
		if(a[x]==d)
		{
			if(x==1||!bf(x-1))
			{
				return 0;
			}
			a[x]=0;
		}
		if((x<=1||a[x]!=a[x-1])&&(x<=2||a[x]!=a[x-2]))
		{
			break;
		}
	}
	return 1;
}

int main()
{
	long long i;
	string s;
	
	scanf("%lld%lld",&n,&d);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
	}
	if(bf(n))
	{
		for(i=1;i<=n;i++)
		{
			printf("%c",a[i]+'a');
		}
		printf("\n");
	}
	else
	{
		printf("NO\n");
	}
}