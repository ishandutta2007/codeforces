#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn,pr[400069],dh[400069],dg[400069],zs=0;
map<pair<long long,long long>,long long> yk;
pair<long long,long long> ed[200069],sq[200059];
vector<pair<long long,long long>> al[400069];
bitset<400069> spc,vtd;
vector<long long> vl[400069];
priority_queue<pair<pair<bool,pair<long long,long long>>,long long>> pq;

void ad(long long x)
{
	if(!dg[x]&&!spc[x])
	{
		pq.push({{vl[x].size()>1,{dh[x],pr[x]}},x});
	}
}

void dfs(long long x,long long b4)
{
	long long i,sz=al[x].size(),l,p;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		p=al[x][i].sc;
		if(p==b4)
		{
			continue;
		}
		if(!vtd[l])
		{
			pr[l]=x;
			vl[l].push_back(p);
			dh[l]=dh[x]+1;
			dg[x]++;
			dfs(l,p);
		}
		else if(dh[l]<dh[x])
		{
			vl[x].push_back(p);
		}
	}
	ad(x);
}

int main()
{
	long long i,ii,k,l,sz,x,x2,y,y2,xx,yy,w,w2,gd;
	bool bad;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld%lld",&x,&x2,&y,&y2);
		for(ii=0;ii<2;ii++)
		{
			xx=x+x2*!ii;
			yy=y+y2*ii;
			w=yy*x2;
			w2=xx*y2;
			gd=__gcd(w,w2);
			w/=gd;
			w2/=gd;
			if(!yk[{w,w2}])
			{
				nn++;
				yk[{w,w2}]=nn;
			}
			k=yk[{w,w2}];
			swap(k,l);
		}
		ed[i]={k,l};
		al[k].push_back({l,i});
		al[l].push_back({k,i});
	}
	for(i=1;i<=nn;i++)
	{
		if(!vtd[i])
		{
			spc[i]=1;
			dfs(i,0);
			for(;!pq.empty();)
			{
				bad=pq.top().fr.fr;
				l=pq.top().fr.sc.sc;
				k=pq.top().sc;
				pq.pop();
				if(bad)
				{
					for(sz=vl[k].size();sz>1;sz-=2)
					{
						zs++;
						sq[zs]={vl[k][sz-1],vl[k][sz-2]};
						for(ii=0;ii<2;ii++)
						{
							vl[k].pop_back();
						}
					}
					if(!sz)
					{
						dg[l]--;
						ad(l);
					}
					else
					{
						ad(k);
					}
				}
				else
				{
					sz=vl[l].size();
					if(dg[l]>1)
					{
						zs++;
						sq[zs]={vl[k][0],vl[pq.top().sc][0]};
						pq.pop();
						dg[l]-=2;
						ad(l);
					}
					else if(sz)
					{
						zs++;
						sq[zs]={vl[k][0],vl[l][sz-1]};
						dg[l]--;
						vl[l].pop_back();
						if(sz>1)
						{
							ad(l);
						}
						else
						{
							dg[pr[l]]--;
							ad(pr[l]);
						}
					}
				}
			}
		}
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld %lld\n",sq[i].fr,sq[i].sc);
	}
}