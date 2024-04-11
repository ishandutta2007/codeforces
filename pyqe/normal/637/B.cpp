#include <bits/stdc++.h>

using namespace std;

long long n;
string s[200069];
map<string,bool> vtd;

int main()
{
	long long i;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	for(i=n;i;i--)
	{
		if(!vtd[s[i]])
		{
			vtd[s[i]]=1;
			printf("%s\n",s[i].c_str());
		}
	}
}