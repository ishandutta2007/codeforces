#include <bits/stdc++.h>

using namespace std;

long long n,m,a[200069],fq[200069],sq[26];

int main()
{
	long long t,rr,i,k,sm;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		cin>>s;
		for(i=1;i<=n;i++)
		{
			a[i]=s[i-1]-'a';
			fq[i]=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld",&k);
			fq[k]++;
		}
		for(i=0;i<26;i++)
		{
			sq[i]=0;
		}
		sm=1;
		for(i=n;i;i--)
		{
			sm+=fq[i];
			sq[a[i]]+=sm;
		}
		for(i=0;i<26;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==25]);
		}
	}
}