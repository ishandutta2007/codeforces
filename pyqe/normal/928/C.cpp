#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,nn=0,nr[1069],sq[1069],zs=0;
string ky[1069];
map<string,long long> yk;
pair<long long,long long> a[1069];
vector<pair<long long,long long>> all[1069];
pair<pair<long long,long long>,long long> com[1069];
vector<long long> al[1069];
priority_queue<pair<pair<long long,long long>,long long>> pq;
bitset<1069> vtd,vtd2;

inline long long val(string s)
{
	if(!yk[s])
	{
		nn++;
		ky[nn]=s;
		yk[s]=nn;
	}
	return yk[s];
}

bool cvr(long long x,long long y)
{
	return a[x].sc>a[y].sc;
}

bool cky(long long x,long long y)
{
	return ky[a[x].fr]<ky[a[y].fr];
}

int main()
{
	long long i,j,k,l,sz,k2,l2;
	string s;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		k=val(s);
		scanf("%lld%lld",&l,&sz);
		a[i]={k,l};
		com[i]={a[i],i};
		for(j=0;j<sz;j++)
		{
			cin>>s;
			k2=val(s);
			scanf("%lld",&l2);
			all[i].push_back({k2,l2});
		}
		nr[i]=inf;
	}
	sort(com+1,com+n+1);
	for(i=1;i<=n;i++)
	{
		sz=all[i].size();
		for(j=0;j<sz;j++)
		{
			k2=all[i][j].fr;
			l2=all[i][j].sc;
			al[i].push_back(lower_bound(com+1,com+n+1,mp(mp(k2,l2),0ll))->sc);
		}
		sort(al[i].begin(),al[i].end(),cvr);
	}
	pq.push({{0,a[1].sc},1});
	nr[1]=0;
	for(;!pq.empty();)
	{
		k=pq.top().sc;
		pq.pop();
		if(vtd[k]||vtd2[a[k].fr])
		{
			continue;
		}
		vtd[k]=1;
		vtd2[a[k].fr]=1;
		if(k!=1)
		{
			zs++;
			sq[zs]=k;
		}
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i];
			if(nr[k]+1<nr[l])
			{
				pq.push({{-nr[k]-1,a[l].sc},l});
				nr[l]=nr[k]+1;
			}
		}
	}
	sort(sq+1,sq+zs+1,cky);
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%s %lld\n",ky[a[sq[i]].fr].c_str(),a[sq[i]].sc);
	}
}