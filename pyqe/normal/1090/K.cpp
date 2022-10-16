#include <bits/stdc++.h>

using namespace std;

long long n,zs=0;
array<bool,26> vtd;
map<pair<string,array<bool,26>>,long long> yk;
vector<long long> sq[100069];

int main()
{
	long long i,j,k,sz;
	string s,s2;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		cin>>s>>s2;
		for(j=0;j<26;j++)
		{
			vtd[j]=0;
		}
		sz=s2.length();
		for(j=0;j<sz;j++)
		{
			vtd[s2[j]-'a']=1;
		}
		sz=s.length();
		for(j=sz;j&&vtd[s[j-1]-'a'];j--);
		s=s.substr(0,j);
		if(!yk[{s,vtd}])
		{
			zs++;
			yk[{s,vtd}]=zs;
		}
		k=yk[{s,vtd}];
		sq[k].push_back(i);
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
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