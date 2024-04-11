#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,k,i;
	string s,t,v;
	map<string,string> m;
	
	scanf("%lld%lld",&n,&k);
	for(i=0;i<k;i++)
	{
		cin>>s>>t;
		if(t.length()<s.length())
		{
			v=t;
		}
		else
		{
			v=s;
		}
		m[s]=v;
		m[t]=v;
	}
	for(i=0;i<n;i++)
	{
		cin>>s;
		if(i>0)
		{
			printf(" ");
		}
		printf("%s",m[s].c_str());
	}
	printf("\n");
}