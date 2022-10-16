#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long ln,i,c=0,sz=0;
	vector<long long> v;
	string s;
	
	scanf("%lld",&ln);
	cin>>s;
	for(i=0;i<ln;i++)
	{
		if(s[i]=='B')
		{
			c++;
		}
		else if(s[i]=='W'&&c>0)
		{
			v.push_back(c);
			sz++;
			c=0;
		}
	}
	if(c>0)
	{
		v.push_back(c);
		sz++;
	}
	printf("%lld\n",sz);
	for(i=0;i<sz;i++)
	{
		if(i>0)
		{
			printf(" ");
		}
		printf("%lld",v[i]);
	}
	printf("\n");
}