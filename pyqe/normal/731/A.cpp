#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long ln,i,z=0;
	char ch='a',c1,c2;
	string s;
	
	cin>>s;
	ln=s.length();
	for(i=0;i<ln;i++)
	{
		c1=min(ch,s[i]);
		c2=max(ch,s[i]);
		z+=min(c2-c1,26+c1-c2);
		ch=s[i];
	}
	printf("%lld\n",z);
}