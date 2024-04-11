#include <bits/stdc++.h>

using namespace std;

long long n,ps[26][200069],fq[26];

int main()
{
	long long t,rr,i,j,k,ln,mx;
	string s;
	
	scanf("%lld",&n);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		k=s[i-1]-'a';
		for(j=0;j<26;j++)
		{
			ps[j][i]=ps[j][i-1];
		}
		ps[k][i]++;
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		ln=s.length();
		for(i=0;i<26;i++)
		{
			fq[i]=0;
		}
		for(i=1;i<=ln;i++)
		{
			k=s[i-1]-'a';
			fq[k]++;
		}
		mx=-1e18;
		for(i=0;i<26;i++)
		{
			k=lower_bound(ps[i],ps[i]+n+1,fq[i])-ps[i];
			mx=max(mx,k);
		}
		printf("%lld\n",mx);
	}
}