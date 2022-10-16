#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,p;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		if(i%2)
		{
			p=(n+1)/2-i/2;
		}
		else
		{
			p=(n+1)/2+i/2;
		}
		printf("%c",s[p-1]);
	}
	printf("\n");
}