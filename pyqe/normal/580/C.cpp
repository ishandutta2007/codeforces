#include <bits/stdc++.h>

using namespace std;

bool vtd[100069];

int main()
{
	long long n,m,i,c=0,k,l,p,z,sz;
	bool g;
	queue<pair<long long,long long>> q; 
	
	scanf("%lld%lld",&n,&m);
	bool ct[n+69];
	vector<long long> al[n+69];
	for(i=1;i<=n;i++)
	{
		scanf("%d",ct+i);
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	if(ct[1])
	{
		q.push(make_pair(1,1));
	}
	else
	{
		q.push(make_pair(1,0));
	}
	vtd[1]=true;
	while(!q.empty())
	{
		p=q.front().first;
		z=q.front().second;
		q.pop();
		g=false;
		sz=al[p].size();
		for(i=0;i<sz;i++)
		{
			if(!vtd[al[p][i]])
			{
				g=true;
				if(ct[al[p][i]])
				{
					if(z>=m)
					{
						continue;
					}
					q.push(make_pair(al[p][i],z+1));
				}
				else
				{
					q.push(make_pair(al[p][i],0));
				}
				vtd[al[p][i]]=true;
			}
		}
		if(!g)
		{
			c++;
		}
	}
	printf("%lld\n",c);
}