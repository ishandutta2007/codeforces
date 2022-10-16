#include <bits/stdc++.h>

using namespace std;

long long n,zs;
multiset<long long> ms[2];
multiset<long long>::iterator it[2];
vector<long long> v;
vector<vector<long long>> sq;

int main()
{
	long long i,j,sz;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		ms[s[i-1]-'0'].insert(i);
	}
	for(zs=0;n;zs++)
	{
		it[0]=ms[0].upper_bound(0);
		if(it[0]==ms[0].end())
		{
			printf("-1\n");
			return 0;
		}
		v.clear();
		for(;1;)
		{
			it[1]=ms[1].upper_bound(*it[0]);
			v.push_back(*it[0]);
			ms[0].erase(it[0]);
			n--;
			if(it[1]==ms[1].end())
			{
				break;
			}
			it[0]=ms[0].upper_bound(*it[1]);
			if(it[0]==ms[0].end())
			{
				break;
			}
			v.push_back(*it[1]);
			ms[1].erase(it[1]);
			n--;
		}
		sq.push_back(v);
	}
	printf("%lld\n",zs);
	for(i=0;i<zs;i++)
	{
		sz=sq[i].size();
		printf("%lld",sz);
		for(j=0;j<sz;j++)
		{
			printf(" %lld",sq[i][j]);
		}
		printf("\n");
	}
}