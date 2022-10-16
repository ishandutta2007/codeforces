#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long i,ln,c=0;
	string s;
	
	cin>>s;
	ln=s.length();
	for(i=0;i<ln;i++)
	{
		c+=s[i]=='a';
	}
	printf("%lld\n",min(ln,c*2-1));
}