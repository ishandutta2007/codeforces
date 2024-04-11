#include <bits/stdc++.h>

using namespace std;

long long n,m,d,dj[300069],pr[300069],zs=0;
bitset<300069> vtd,vtd2;
vector<pair<long long,long long>> al[300069];
vector<long long> al2[300069],z;
queue<long long> q;
priority_queue<pair<long long,long long>> pq;
map<pair<long long,long long>,long long> ky;

int main()
{
	long long i,k,l,w,sz,h;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	if(d==0)
	{
		printf("0\n");
		return 0;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		al[k].push_back(make_pair(l,w));
		al[l].push_back(make_pair(k,w));
		ky[make_pair(k,l)]=i;
		ky[make_pair(l,k)]=i;
	}
	pq.push(make_pair(0,1));
	dj[1]=0;
	while(!pq.empty())
	{
		k=pq.top().second;
		w=pq.top().first;
		pq.pop();
		if(vtd[k])
		{
			continue;
		}
		vtd[k]=true;
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i].first;
			h=al[k][i].second;
			if(vtd[l]||(dj[l]>0&&w-h<=-dj[l]))
			{
				continue;
			}
			pq.push(make_pair(w-h,l));
			dj[l]=-w+h;
			pr[l]=k;
		}
	}
	for(i=1;i<=n;i++)
	{
		al2[pr[i]].push_back(i);
	}
	q.push(1);
	vtd2[1]=true;
	while(!q.empty())
	{
		k=q.front();
		q.pop();
		sz=al2[k].size();
		for(i=0;i<sz;i++)
		{
			l=al2[k][i];
			if(!vtd2[l])
			{
				q.push(l);
				vtd2[l]=true;
				z.push_back(ky[make_pair(k,l)]);
				zs++;
				if(zs>=min(d,n-1))
				{
					break;
				}
			}
		}
		if(zs>=min(d,n))
		{
			break;
		}
	}
	printf("%lld\n",zs);
	for(i=0;i<zs;i++)
	{
		if(i>0)
		{
			printf(" ");
		}
		printf("%lld",z[i]);
	}
	printf("\n");
}