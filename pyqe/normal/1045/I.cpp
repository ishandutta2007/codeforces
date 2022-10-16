#include <bits/stdc++.h>

using namespace std;

long long n,ln;
map<long long,long long> fq;

int main()
{
	long long i,j,mk,mkk,k,z=0;
	string s;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		cin>>s;
		ln=s.length();
		mk=0;
		for(j=1;j<=ln;j++)
		{
			k=s[j-1]-'a';
			mk^=1ll<<k;
		}
		for(j=-1;j<26;j++)
		{
			mkk=mk;
			if(j+1)
			{
				mkk^=1ll<<j;
			}
			z+=fq[mkk];
		}
		fq[mk]++;
	}
	printf("%lld\n",z);
}