#include <bits/stdc++.h>

using namespace std;

const long long dv=1e9+7;
long long n;

int main()
{
	long long i,ml=0,z=0;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=0;i<n;i++)
	{
		if(s[i]=='a')
		{
			ml=(ml*2+1)%dv;
		}
		else
		{
			z=(z+ml)%dv;
		}
	}
	printf("%lld\n",z);
}