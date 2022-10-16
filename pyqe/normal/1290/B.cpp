#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];
vector<long long> pst[26];

int main()
{
	long long t,rr,i,k,l,z,p;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'a';
		pst[a[i]].push_back(i);
	}
	for(i=0;i<26;i++)
	{
		pst[i].push_back(n+1);
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		z=0;
		for(i=0;i<26;i++)
		{
			p=*lower_bound(pst[i].begin(),pst[i].end(),k);
			if(p<=l)
			{
				z++;
			}
		}
		if(k==l||(z==2&&a[k]!=a[l])||z>2)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}