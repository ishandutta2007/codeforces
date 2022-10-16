#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long i,ln;
	string s;
	
	cin>>s;
	ln=s.length();
	for(i=0;i<ln;i++)
	{
		if(i==0&&s[i]=='9')
		{
			continue;
		}
		if(s[i]>'4')
		{
			s[i]='9'-s[i]+'0';
		}
	}
	printf("%s\n",s.c_str());
}