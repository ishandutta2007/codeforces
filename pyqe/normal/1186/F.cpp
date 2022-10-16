#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,dg[1000069],p[1000069],ln,zs=0;
vector<long long> al[1000069];
vector<pair<long long,long long>> sq;
pair<long long,long long> eu[2000069];
map<pair<long long,long long>,bool> ve;
bitset<2000069> spc;

int main()
{
	long long i,j,k,l;
	bool u;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
		dg[k]++;
		dg[l]++;
	}
	for(i=1;i<=n;i++)
	{
		if(dg[i]%2)
		{
			al[0].push_back(i);
			al[i].push_back(0);
			dg[0]++;
			dg[i]++;
		}
	}
	for(i=0;i<=n;i++)
	{
		ln=0;
		for(k=i;p[i]<dg[i];)
		{
			for(;p[k]<dg[k];p[k]++)
			{
				l=al[k][p[k]];
				if(!ve[{k,l}])
				{
					eu[ln]={k,l};
					spc[ln]=!k||!l;
					ln++;
					ve[{k,l}]=1;
					ve[{l,k}]=1;
					p[k]++;
					k=l;
					break;
				}
			}
		}
		u=0;
		for(j=0;j<ln;j++)
		{
			if(!spc[j])
			{
				if(spc[(j+ln-1)%ln]||spc[(j+1)%ln])
				{
					u=1;
				}
				else
				{
					u^=1;
				}
				if(u)
				{
					sq.push_back(eu[j]);
					zs++;
				}
			}
		}
	}
	printf("%lld\n",zs);
	for(i=0;i<zs;i++)
	{
		printf("%lld %lld\n",sq[i].fr,sq[i].sc);
	}
}