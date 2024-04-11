#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long i,j;
	string s,s2;
	
	cin>>s>>s2;
	n=s.length();
	m=s2.length();
	for(j=0,i=0;i<m;i++)
	{
		if(j<n&&s[j]==s2[i])
		{
			j++;
		}
	}
	printf("%lld\n",j+1);
}