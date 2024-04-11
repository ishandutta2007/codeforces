#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		if(s.substr(n-2,2)=="po")
		{
			printf("FILIPINO\n");
		}
		else if(s.substr(n-4,4)=="desu"||s.substr(n-4,4)=="masu")
		{
			printf("JAPANESE\n");
		}
		else if(s.substr(n-5,5)=="mnida")
		{
			printf("KOREAN\n");
		}
	}
}