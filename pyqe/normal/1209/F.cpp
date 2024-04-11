#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nr[100069],c,z[500069],dv=1e9+7,dm;
bitset<500069> vtd;
vector<pair<long long,long long>> al[100069],pr[100069];
vector<long long> cd[500069][10];
priority_queue<pair<long long,long long>> pq;
stack<long long> prv;

void dfs(vector<long long> v)
{
	long long i,j,l,ix,sz=0;
	vector<long long> vv;
	
	for(ix=0;ix<10;ix++)
	{
		for(i=0;i<v.size();i++)
		{
			sz=cd[v[i]][ix].size();
			for(j=0;j<sz;j++)
			{
				l=cd[v[i]][ix][j];
				if(!vtd[l])
				{
					vv.push_back(l);
					z[l]=(prv.top()*10+ix)%dv;
					vtd[l]=1;
				}
			}
		}
		if(!vv.empty())
		{
			prv.push((prv.top()*10+ix)%dv);
			dfs(vv);
			prv.pop();
			vv.clear();
		}
	}
}

int main()
{
	long long i,k,l,w,sz,ix,j,kk,ll;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back({l,i});
		al[l].push_back({k,i});
	}
	for(i=1;i<=n;i++)
	{
		nr[i]=1e18;
	}
	pq.push({0,1});
	nr[1]=0;
	for(;!pq.empty();)
	{
		k=pq.top().sc;
		w=-pq.top().fr;
		pq.pop();
		if(vtd[k])
		{
			continue;
		}
		vtd[k]=1;
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i].fr;
			ix=al[k][i].sc;
			for(kk=ix,c=0;kk>0;kk/=10,c++);
			if(w+c<nr[l])
			{
				pq.push({-w-c,l});
				nr[l]=w+c;
				pr[l].clear();
			}
			if(w+c==nr[l])
			{
				pr[l].push_back({k,ix});
			}
		}
	}
	dm=n;
	for(i=1;i<=n;i++)
	{
		sz=pr[i].size();
		for(j=0;j<sz;j++)
		{
			ll=pr[i][j].fr;
			ix=pr[i][j].sc;
			for(kk=ix;kk>0;kk/=10)
			{
				if(kk==ix)
				{
					l=i;
				}
				else
				{
					dm++;
					l=dm;
				}
				if(kk<10)
				{
					k=ll;
				}
				else
				{
					k=dm+1;
				}
				cd[k][kk%10].push_back(l);
			}
		}
	}
	for(i=1;i<=dm;i++)
	{
		for(ix=0;ix<10;ix++)
		{
			sz=cd[i][ix].size();
			for(j=0;j<sz;j++)
			{
				l=cd[i][ix][j];
			}
		}
		vtd[i]=0;
	}
	prv.push(0);
	vtd[1]=1;
	dfs({1});
	for(i=2;i<=n;i++)
	{
		printf("%lld\n",z[i]);
	}
}