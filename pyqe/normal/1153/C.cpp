#include <bits/stdc++.h>

using namespace std;

long long n,fq[2];
bitset<300069> a,vtd;

int main()
{
	long long i,c=0,sm=0;
	string s;
	char ch;
	
	scanf("%lld",&n);
	if(n%2)
	{
		printf(":(\n");
		return 0;
	}
	cin>>s;
	for(i=1;i<=n;i++)
	{
		ch=s[i-1];
		if(ch!='?')
		{
			vtd[i]=1;
			a[i]=ch=='(';
			if(i-1&&i<n)
			{
				fq[a[i]]++;
			}
		}
	}
	if((vtd[1]&&!a[1])||(vtd[n]&&a[n])||max(fq[0],fq[1])>(n-2)/2)
	{
		printf(":(\n");
		return 0;
	}
	a[1]=1;
	a[n]=0;
	for(i=2;i<=n-1;i++)
	{
		if(!vtd[i])
		{
			c++;
			a[i]=c<=(n-2)/2-fq[1];
		}
		sm+=a[i]*2-1;
		if(sm<0)
		{
			printf(":(\n");
			return 0;
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%c",")("[a[i]]);
	}
	printf("\n");
}