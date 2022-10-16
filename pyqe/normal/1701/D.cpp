#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,pst[500069],sq[500069];
vector<long long> vl[500069];
priority_queue<pair<long long,long long>> pq;

int main()
{
	long long t,rr,i,j,k,w,sz,lh,rh,md,zz;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			vl[i].clear();
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&w);
			for(lh=1,rh=n;lh<=rh;)
			{
				md=(lh+rh)/2;
				if(i/md<=w)
				{
					zz=md;
					rh=md-1;
				}
				else
				{
					lh=md+1;
				}
			}
			vl[zz].push_back(i);
			for(lh=1,rh=n;lh<=rh;)
			{
				md=(lh+rh)/2;
				if(i/md>=w)
				{
					zz=md;
					lh=md+1;
				}
				else
				{
					rh=md-1;
				}
			}
			pst[i]=zz;
		}
		for(i=1;i<=n;i++)
		{
			sz=vl[i].size();
			for(j=0;j<sz;j++)
			{
				k=vl[i][j];
				pq.push({-pst[k],k});
			}
			sq[pq.top().sc]=i;
			pq.pop();
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==n]);
		}
	}
}