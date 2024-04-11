#include <bits/stdc++.h>

using namespace std;

long long n,fq[26][27];

int main()
{
	long long i,j,k,mx=-1e18;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		k=s[i-1]-'a';
		for(j=0;j<26;j++)
		{
			fq[j][k]+=fq[j][26];
			mx=max(mx,fq[j][k]);
		}
		fq[k][26]++;
		mx=max(mx,fq[k][26]);
	}
	printf("%lld\n",mx);
}