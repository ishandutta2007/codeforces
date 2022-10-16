#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k;
	bool bad=0;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		k=s[i-1]-'0';
		if(!bad&&(!k||i==n))
		{
			bad=1;
		}
		else
		{
			printf("%lld",k);
		}
	}
	printf("\n");
}