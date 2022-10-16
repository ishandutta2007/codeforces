#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i;
	string s;
	char mx='a';
	
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++)
	{
		mx=max(mx,s[i]);
	}
	for(i=0;i<n;i++)
	{
		if(s[i]==mx)
		{
			printf("%c",s[i]);
		}
	}
	printf("\n");
}