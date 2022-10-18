#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long ln,i,k,l,z=0;
	string s,t;
	
	scanf("%lld",&ln);
	cin>>s>>t;
	for(i=0;i<ln;i++)
	{
		if(s[i]<t[i])
		{
			k=s[i]-48;
			l=t[i]-48;
		}
		else
		{
			k=t[i]-48;
			l=s[i]-48;
		}
		z+=min(l-k,10+k-l);
	}
	printf("%lld\n",z);
}