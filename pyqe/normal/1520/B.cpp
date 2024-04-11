#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i;
	bool bad;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		bad=0;
		for(i=1;i<n;i++)
		{
			if(s[i]>s[0])
			{
				break;
			}
			else if(s[i]<s[0])
			{
				bad=1;
				break;
			}
		}
		printf("%lld\n",(n-1)*9+(s[0]-'0')-bad);
	}
}