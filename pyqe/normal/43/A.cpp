#include <bits/stdc++.h>

using namespace std;

long long n;
map<string,long long> fq;

int main()
{
	long long i,mx=0;
	string s,z;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		cin>>s;
		fq[s]++;
		if(fq[s]>mx)
		{
			mx=fq[s];
			z=s;
		}
	}
	printf("%s\n",z.c_str());
}