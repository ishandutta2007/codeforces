#include <bits/stdc++.h>

using namespace std;

long long n,fq[2];

int main()
{
	long long i,ii,k;
	string s;
	
	for(ii=0;ii<2;ii++)
	{
		cin>>s;
		n=s.length();
		for(i=1;i<=n;i++)
		{
			k=s[i-1]-'0';
			fq[ii]+=k;
		}
	}
	fq[0]+=fq[0]%2;
	if(fq[1]<=fq[0])
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}