#include <bits/stdc++.h>

using namespace std;

long long ln,n,a[100069],d[100069];

int main()
{
	long long i,j;
	string s;
	bool bad=1,sm;
	
	scanf("%lld",&n);
	cin>>s;
	ln=s.length();
	for(i=0;i<ln;i++)
	{
		a[i]=s[i]-'0';
		if(a[i]<9)
		{
			bad=0;
		}
	}
	if(bad||ln%n!=0)
	{
		for(i=0;i<ln/n+1;i++)
		{
			printf("1");
			for(j=0;j<n-1;j++)
			{
				printf("0");
			}
		}
		printf("\n");
		return 0;
	}
	for(i=0;i<n;i++)
	{
		d[i]=a[i];
	}
	bad=0;
	sm=1;
	for(i=n;i<ln;i++)
	{
		if(a[i]!=d[i%n])
		{
			sm=0;
		}
		if(a[i]<d[i%n])
		{
			break;
		}
		if(a[i]>d[i%n])
		{
			bad=1;
			break;
		}
	}
	if(bad||sm)
	{
		for(i=n-1;1;i--)
		{
			d[i]=(d[i]+1)%10;
			if(d[i]!=0)
			{
				break;
			}
		}
	}
	for(i=0;i<ln/n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%lld",d[j]);
		}
	}
	printf("\n");
}