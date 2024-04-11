#include <bits/stdc++.h>

using namespace std;

long long n,m;
vector<long long> pst[26];

int main()
{
	long long i,k,ls=0,p,z=1;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		k=s[i-1]-'a';
		pst[k].push_back(i);
	}
	for(i=0;i<26;i++)
	{
		pst[i].push_back(n+1);
	}
	cin>>s;
	m=s.length();
	for(i=1;i<=m;i++)
	{
		k=s[i-1]-'a';
		p=*upper_bound(pst[k].begin(),pst[k].end(),ls);
		if(p<=n)
		{
			ls=p;
		}
		else
		{
			if(ls)
			{
				ls=0;
				z++;
				i--;
			}
			else
			{
				z=-1;
				break;
			}
		}
	}
	printf("%lld\n",z);
}