#include <bits/stdc++.h>

using namespace std;

long long n,m,a[200069];
bitset<26> spc;

int main()
{
	long long i,c=0,z=0;
	string s;
	char ch;
	
	scanf("%lld%lld",&n,&m);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
	}
	for(i=0;i<m;i++)
	{
		scanf(" %c",&ch);
		spc[ch-'a']=1;
	}
	for(i=1;i<=n;i++)
	{
		if(spc[a[i]])
		{
			c++;
			if(i==n||!spc[a[i+1]])
			{
				z+=c*(c+1)/2;
				c=0;
			}
		}
	}
	printf("%lld\n",z);
}