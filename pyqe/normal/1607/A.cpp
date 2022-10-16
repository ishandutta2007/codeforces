#include <bits/stdc++.h>

using namespace std;

long long n,pst[26];

int main()
{
	long long t,rr,i,k,l,z;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=0;i<n;i++)
		{
			pst[s[i]-'a']=i;
		}
		cin>>s;
		n=s.length();
		z=0;
		for(i=0;i<n;i++)
		{
			k=s[i]-'a';
			if(i)
			{
				z+=abs(pst[k]-pst[l]);
			}
			l=k;
		}
		printf("%lld\n",z);
	}
}