#include <bits/stdc++.h>

using namespace std;

long long n;
map<long long,long long> fq;

int main()
{
	long long t,rr,i,k,sm,z;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		cin>>s;
		fq.clear();
		z=0;
		sm=0;
		fq[0]++;
		for(i=1;i<=n;i++)
		{
			k=s[i-1]-'1';
			sm+=k;
			z+=fq[sm];
			fq[sm]++;
		}
		printf("%lld\n",z);
	}
}