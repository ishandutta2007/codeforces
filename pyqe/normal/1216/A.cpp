#include <bits/stdc++.h>

using namespace std;

long long ln;

int main()
{
	long long i,c=0;
	string s;
	
	scanf("%lld",&ln);
	cin>>s;
	for(i=0;i<ln;i+=2)
	{
		if(s[i]==s[i+1])
		{
			s[i]=1-(s[i]-'a')+'a';
			c++;
		}
	}
	printf("%lld\n%s\n",c,s.c_str());
}