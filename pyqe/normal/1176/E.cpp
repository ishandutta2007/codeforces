#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,sq[2][200069],zs[0];
vector<long long> al[200069];
queue<pair<long long,bool>> q;
bitset<200069> vtd;

int main()
{
	long long t,rr,i,ii,k,l,w,sz,e;
	pair<long long,long long> mne;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
			vtd[i]=0;
		}
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld",&k,&l);
			al[k].push_back(l);
			al[l].push_back(k);
		}
		for(ii=0;ii<2;ii++)
		{
			zs[ii]=0;
		}
		q.push({1,0});
		vtd[1]=1;
		for(;!q.empty();)
		{
			k=q.front().fr;
			w=q.front().sc;
			q.pop();
			zs[w]++;
			sq[w][zs[w]]=k;
			sz=al[k].size();
			for(i=0;i<sz;i++)
			{
				l=al[k][i];
				if(!vtd[l])
				{
					q.push({l,!w});
					vtd[l]=1;
				}
			}
		}
		mne=min(mp(zs[0],0),{zs[1],1});
		e=mne.sc;
		printf("%lld\n",zs[e]);
		for(i=1;i<=zs[e];i++)
		{
			printf("%lld%c",sq[e][i]," \n"[i==zs[e]]);
		}
	}
}