#include <bits/stdc++.h>

using namespace std;

long long n;
map<string,string> yk;

int main()
{
	long long t,rr,i;
	string s,s2;
	
	scanf("%lld%lld",&n,&t);
	for(i=0;i<n;i++)
	{
		cin>>s>>s2;
		s2=s2+';';
		yk[s2]=s;
	}
	for(rr=0;rr<t;rr++)
	{
		cin>>s>>s2;
		printf("%s %s #%s\n",s.c_str(),s2.c_str(),yk[s2].c_str());
	}
}