#include <bits/stdc++.h>

using namespace std;

long long n,pr[200069],ls[26];
bitset<200069> vtd;

long long fd(long long x)
{
	if(pr[x]!=x)
	{
		pr[x]=fd(pr[x]);
	}
	return pr[x];
}

int main()
{
	long long ln,i,j,k,z=0;
	string s;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		pr[i]=i;
	}
	for(i=1;i<=n;i++)
	{
		cin>>s;
		ln=s.length();
		for(j=0;j<ln;j++)
		{
			k=s[j]-'a';
			if(ls[k])
			{
				pr[fd(ls[k])]=fd(i);
			}
			ls[k]=i;
		}
	}
	for(i=1;i<=n;i++)
	{
		z+=!vtd[fd(i)];
		vtd[fd(i)]=1;
	}
	printf("%lld\n",z);
}