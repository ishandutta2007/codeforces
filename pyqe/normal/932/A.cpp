#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i;
	string s;
	
	cin>>s;
	n=s.length();
	printf("%s",s.c_str());
	for(i=n-1;i>=0;i--)
	{
		printf("%c",s[i]);
	}
	printf("\n");
}