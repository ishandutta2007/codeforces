#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,fq[10];
vector<pair<long long,long long>> ky[10];

int main()
{
	long long i,j,k,l,w,sz;
	string s;
	
	ky[2].push_back({2,1});
	ky[3].push_back({3,1});
	ky[4].push_back({2,2});
	ky[4].push_back({3,1});
	ky[5].push_back({5,1});
	ky[6].push_back({3,1});
	ky[6].push_back({5,1});
	ky[7].push_back({7,1});
	ky[8].push_back({2,3});
	ky[8].push_back({7,1});
	ky[9].push_back({2,1});
	ky[9].push_back({3,2});
	ky[9].push_back({7,1});
	scanf("%lld",&n);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		fq[s[i-1]-'0']++;
	}
	for(i=9;i>1;i--)
	{
		k=fq[i];
		fq[i]=0;
		sz=ky[i].size();
		for(j=0;j<sz;j++)
		{
			l=ky[i][j].fr;
			w=ky[i][j].sc;
			fq[l]+=k*w;
		}
	}
	for(i=9;i>1;i--)
	{
		for(j=0;j<fq[i];j++)
		{
			printf("%lld",i);
		}
	}
	printf("\n");
}