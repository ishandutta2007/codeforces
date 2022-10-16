#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long ln,i,c=0;
	string s,z="";
	
	scanf("%lld",&ln);
	cin>>s;
	for(i=0;i<ln;i+=c)
	{
		z=z+s[i];
		c++;
	}
	printf("%s\n",z.c_str());
}