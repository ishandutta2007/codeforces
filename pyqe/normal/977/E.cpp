#include <bits/stdc++.h>

using namespace std;

queue<long long> q;
bitset<200069> vtd;
vector<long long> al[200069];

int main()
{
	long long n,m,i,k,l,sz,z=0,j;
	bool g;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	for(i=1;i<=n;i++)
	{
		if(vtd[i])
		{
			continue;
		}
		q.push(i);
		vtd[i]=true;
		g=true;
		while(!q.empty())
		{
			k=q.front();
			q.pop();
			sz=al[k].size();
			if(sz!=2)
			{
				g=false;
			}
			for(j=0;j<sz;j++)
			{
				if(!vtd[al[k][j]])
				{
					q.push(al[k][j]);
					vtd[al[k][j]]=true;
				}
			}
		}
		if(g)
		{
			z++;
		}
	}
	printf("%lld\n",z);
}