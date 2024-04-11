#include <bits/stdc++.h>

using namespace std;

const long long mm=26;
long long n;
bitset<mm> vtd;

int main()
{
	long long t,rr,i,k,z;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		z=0;
		vtd.reset();
		for(i=0;i<n;i++)
		{
			k=s[i]-'a';
			if(vtd[k])
			{
				z+=2;
				vtd.reset();
			}
			else
			{
				vtd[k]=1;
			}
		}
		printf("%lld\n",n-z);
	}
}