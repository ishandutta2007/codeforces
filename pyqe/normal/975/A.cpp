#include <bits/stdc++.h>

using namespace std;

long long n;
map<long long,bool> vtd;

int main()
{
	long long i,j,sz,mk,z=0;
	string s;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		cin>>s;
		sz=s.length();
		mk=0;
		for(j=0;j<sz;j++)
		{
			mk|=1ll<<s[j]-'a';
		}
		z+=!vtd[mk];
		vtd[mk]=1;
	}
	printf("%lld\n",z);
}