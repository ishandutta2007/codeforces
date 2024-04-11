#include <bits/stdc++.h>

using namespace std;

map<string,bool> vtd;

int main()
{
	long long t,rr;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		if(!vtd[s])
		{
			printf("NO\n");
			vtd[s]=1;
		}
		else
		{
			printf("YES\n");
		}
	}
}