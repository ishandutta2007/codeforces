#include <bits/stdc++.h>

using namespace std;

long long ln,n,a[200069],d[200069];

int main()
{
	long long i,j;
	string s;
	bool bad=0;
	
	scanf("%lld%lld",&ln,&n);
	cin>>s;
	ln=s.length();
	for(i=0;i<ln;i++)
	{
		a[i]=s[i]-'0';
	}
	for(i=0;i<n;i++)
	{
		d[i]=a[i];
	}
	for(i=n;i<ln;i++)
	{
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
	if(bad)
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
	printf("%lld\n",ln);
	for(i=0;i<ln;i++)
	{
		printf("%lld",d[i%n]);
	}
	printf("\n");
}