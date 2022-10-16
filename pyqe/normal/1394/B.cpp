#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,fq[200069][10][10],sq[10];
vector<pair<long long,long long>> al[200069];
bitset<10> am[10][10][10];

int main()
{
	long long i,j,r,j2,r2,k,l,w,sz,z=0;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		al[k].push_back({w,l});
	}
	for(i=1;i<=n;i++)
	{
		sort(al[i].begin(),al[i].end());
		sz=al[i].size();
		for(j=0;j<sz;j++)
		{
			l=al[i][j].sc;
			fq[l][sz][j+1]++;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=d;j++)
		{
			for(r=1;r<=j;r++)
			{
				if(fq[i][j][r])
				{
					am[j][r][j][r]=am[j][r][j][r]|fq[i][j][r]>1;
					for(j2=j;j2<=d;j2++)
					{
						for(r2=1+r*(j2==j);r2<=j2;r2++)
						{
							am[j][r][j2][r2]=am[j][r][j2][r2]|fq[i][j2][r2];
						}
					}
				}
			}
		}
	}
	for(i=1;i<=d;i++)
	{
		sq[i]=1;
	}
	for(;1;)
	{
		for(i=1;i&&i<=d;i++)
		{
			for(j=1;j<=d;j++)
			{
				if(am[i][sq[i]][j][sq[j]])
				{
					i=-1;
					break;
				}
			}
		}
		z+=!!i;
		sq[1]++;
		for(i=1;sq[i]>i;i++)
		{
			sq[i]=1;
			sq[i+1]++;
		}
		if(i>d)
		{
			break;
		}
	}
	printf("%lld\n",z);
}