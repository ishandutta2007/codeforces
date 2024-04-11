#include <bits/stdc++.h>

using namespace std;

long long ln,c[3];
string s;

int main()
{
	long long i;
	
	cin>>s;
	ln=s.length();
	for(i=0;i<ln;i++)
	{
		if(s[i]=='Q')
		{
			c[0]++;
			c[2]+=c[1];
		}
		else if(s[i]=='A')
		{
			c[1]+=c[0];
		}
	}
	printf("%lld\n",c[2]);
}