#include <bits/stdc++.h>

using namespace std;

long long ln;
string s;
map<string,long long> fq;

int main()
{
	long long i,mx=0;
	string z;
	
	scanf("%lld",&ln);
	cin>>s;
	for(i=0;i<ln-1;i++)
	{
		fq[s.substr(i,2)]++;
		if(fq[s.substr(i,2)]>mx)
		{
			mx=fq[s.substr(i,2)];
			z=s.substr(i,2);
		}
	}
	printf("%s\n",z.c_str());
}