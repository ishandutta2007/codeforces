#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		if(s[0]!=s[n-1])
		{
			s[0]=s[n-1];
		}
		printf("%s\n",s.c_str());
	}
}