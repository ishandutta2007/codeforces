#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,mn=1e18;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		k=s[i-1]-'a';
		if(k>mn)
		{
			printf("Ann\n");
		}
		else
		{
			printf("Mike\n");
		}
		mn=min(mn,k);
	}
}