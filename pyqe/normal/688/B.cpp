#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long ln,i;
	string s;
	
	cin>>s;
	ln=s.length();
	printf("%s",s.c_str());
	for(i=ln-1;i>=0;i--)
	{
		printf("%c",s[i]);
	}
	printf("\n");
}