#include <bits/stdc++.h>

using namespace std;

long long n;
map<string,long long> dp;

string lwr(string s)
{
	long long i,ln=s.length();
	
	for(i=0;i<ln;i++)
	{
		s[i]=s[i]+32*(s[i]<='Z');
	}
	return s;
}

int main()
{
	long long i,k,z=0;
	string s,s2;
	
	scanf("%lld",&n);
	dp["polycarp"]=1;
	for(i=0;i<n;i++)
	{
		cin>>s>>s2>>s2;
		k=dp[lwr(s2)]+1;
		dp[lwr(s)]=k;
		z=max(z,k);
	}
	printf("%lld\n",z);
}