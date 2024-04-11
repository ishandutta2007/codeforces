#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i;
	string s;
	bool bad=1;
	
	cin>>s;
	n=s.length();
	for(i=2;i<=n;i++)
	{
		if(s[i-1]=='1')
		{
			bad=0;
			break;
		}
	}
	printf("%lld\n",(n-bad+1)/2);
}