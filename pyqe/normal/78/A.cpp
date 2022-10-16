#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long i,j,ln,c;
	string s;
	
	for(i=0;i<3;i++)
	{
		getline(cin,s);
		ln=s.length();
		c=0;
		for(j=0;j<ln;j++)
		{
			c+=s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u';
		}
		if(c!=5+2*(i==1))
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}