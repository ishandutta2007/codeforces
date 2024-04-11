#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0;
pair<long long,long long> sq[69];
vector<pair<long long,long long>> ky[69];
bitset<9> spc[9];

int main()
{
	long long i,j,u,k,l,sz;
	
	for(i=1;i<=8;i++)
	{
		u=i%2*2-1;
		for(j=1+(7-(i>6))*!(i%2);j&&j<=8-(i>6);j+=u)
		{
			k=i;
			if(i>6)
			{
				k=15-k;
			}
			nn++;
			sq[nn]={k,j};
		}
	}
	sq[63]={7,8};
	sq[64]={8,8};
	ky[1].push_back({1,1});
	ky[2].push_back({8,8});
	for(i=1;i<=6;i++)
	{
		ky[i+2].push_back({i,8});
	}
	ky[9].push_back({1,2});
	ky[10].push_back({1,2});
	ky[10].push_back({2,1});
	ky[10].push_back({3,1});
	ky[11].push_back({1,2});
	ky[12].push_back({1,2});
	ky[12].push_back({4,1});
	ky[12].push_back({5,1});
	ky[13].push_back({1,2});
	ky[14].push_back({1,2});
	ky[14].push_back({6,1});
	ky[14].push_back({8,1});
	ky[15].push_back({8,7});
	ky[16].push_back({1,2});
	ky[17].push_back({1,2});
	ky[17].push_back({7,7});
	ky[17].push_back({7,8});
	for(i=1;i<=17;i++)
	{
		sz=ky[i].size();
		for(j=0;j<sz;j++)
		{
			k=ky[i][j].fr;
			l=ky[i][j].sc;
			spc[k][l]=!spc[k][l];
		}
	}
	nn=17;
	for(i=1;i<=8;i++)
	{
		for(j=1;j<=8;j++)
		{
			if(!spc[i][j])
			{
				nn++;
				ky[nn].push_back({i,j});
			}
		}
	}
	for(i=1;i<=8;i++)
	{
		spc[i].reset();
	}
	scanf("%lld",&n);
	for(i=1;i<=n+1;i++)
	{
		sz=ky[i].size();
		for(j=0;j<sz;j++)
		{
			k=ky[i][j].fr;
			l=ky[i][j].sc;
			spc[k][l]=!spc[k][l];
		}
	}
	nn=0;
	for(i=1;i<=64;i++)
	{
		k=sq[i].fr;
		l=sq[i].sc;
		if(spc[k][l])
		{
			nn++;
			printf("%c%lld%c",(char)k+'a'-1,l," \n"[nn==n+1]);
		}
	}
}