#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,ne,nn,wg[200069],nr[20069],rt[10069],c,inf=1e18;
pair<long long,long long> ed[100069],as[100069];
map<pair<long long,long long>,bool> alr;
bitset<100069> se;
vector<pair<long long,long long>> al[20069],pr[20069];
queue<long long> q;
bitset<20069> vtd,spc;
bool r0;

void ae(long long x,long long y,long long w)
{
	wg[ne+1]=w;
	wg[ne+2]=0;
	al[x].push_back({y,ne+1});
	al[y].push_back({x,ne+2});
	ne+=2;
}

void dfs(long long x)
{
	long long i,sz=pr[x].size(),l,p;
	
	vtd[x]=1;
	if(!spc[x]&&x<=n)
	{
		r0=1;
		spc[x]=1;
		c++;
		return;
	}
	for(i=0;i<sz;i++)
	{
		l=pr[x][i].fr;
		p=pr[x][i].sc;
		if(!vtd[l])
		{
			dfs(l);
			if(r0)
			{
				spc[x]=1;
				wg[p]=0;
				wg[(p-1)/2*2+1+p%2]=1;
				return;
			}
		}
	}
}

int main()
{
	long long i,k,l,w,p,sz,lh,rh,md,zz,ds;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		ed[i]={k,n+l};
		as[i]={w,i};
	}
	sort(as+1,as+m+1);
	as[m+1].fr=-1;
	for(i=1;i<=m;i++)
	{
		p=as[i].sc;
		k=ed[p].fr;
		l=ed[p].sc;
		if(alr[{k,l}])
		{
			se[i]=1;
		}
		alr[{k,l}]=1;
	}
	zz=m+1;
	for(lh=n,rh=m;lh<=rh;)
	{
		md=(lh+rh)/2;
		for(i=1;i<=n*2;i++)
		{
			al[i].clear();
		}
		ne=0;
		for(i=1;i<=md;i++)
		{
			if(!se[i])
			{
				p=as[i].sc;
				k=ed[p].fr;
				l=ed[p].sc;
				ae(k,l,1);
			}
		}
		c=0;
		spc.reset();
		for(;1;)
		{
			for(i=1;i<=n*2;i++)
			{
				nr[i]=inf;
			}
			ds=inf;
			nn=0;
			vtd.reset();
			for(i=1;i<=n;i++)
			{
				if(!spc[i])
				{
					q.push(i);
					nr[i]=0;
				}
			}
			for(;!q.empty();)
			{
				k=q.front();
				q.pop();
				if(nr[k]>=ds)
				{
					continue;
				}
				sz=al[k].size();
				for(i=0;i<sz;i++)
				{
					l=al[k][i].fr;
					p=al[k][i].sc;
					if(wg[p])
					{
						if(nr[k]+1<nr[l])
						{
							q.push(l);
							nr[l]=nr[k]+1;
							pr[l].clear();
						}
						if(nr[k]+1==nr[l])
						{
							pr[l].push_back({k,p});
						}
						if(!spc[l]&&!vtd[l])
						{
							ds=nr[k]+1;
							nn++;
							rt[nn]=l;
							vtd[l]=1;
						}
					}
				}
			}
			if(!nn)
			{
				break;
			}
			vtd.reset();
			for(i=1;i<=nn;i++)
			{
				r0=0;
				dfs(rt[i]);
			}
		}
		if(c==n)
		{
			zz=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	printf("%lld\n",as[zz].fr);
}