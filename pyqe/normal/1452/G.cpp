#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,rr,cr,ctd,nr[200069],ls[200069],sbt[200069],dhh[200069],pr[200069],dh[18][200069],inf=1e18;
vector<long long> al[200069];
queue<long long> q;
multiset<pair<long long,long long>> ms[200069];

void bd(long long x)
{
	long long i,sz=al[x].size(),l;
	
	ls[x]=rr*3;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(ls[l]<rr*3)
		{
			bd(l);
			sbt[x]+=sbt[l];
		}
	}
}

void bd2(long long x)
{
	long long i,sz=al[x].size(),l,mx=sbt[cr]-sbt[x];
	
	ls[x]=rr*3+1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(ls[l]<rr*3+1)
		{
			bd2(l);
			mx=max(mx,sbt[l]);
		}
	}
	if(mx*2<=sbt[cr])
	{
		ctd=x;
	}
}

void bd3(long long x)
{
	long long i,sz=al[x].size(),l;
	multiset<pair<long long,long long>>::iterator it;
	
	ls[x]=rr*3+2;
	it=ms[ctd].upper_bound({dh[rr][x]-nr[x],inf});
	if(it==ms[ctd].begin()||prev(it)->sc<nr[x])
	{
		it=ms[ctd].lower_bound({dh[rr][x]-nr[x],-inf});
		for(;it!=ms[ctd].end()&&it->sc<=nr[x];)
		{
			it++;
			ms[ctd].erase(prev(it));
		}
		ms[ctd].insert({dh[rr][x]-nr[x],nr[x]});
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(ls[l]<rr*3+2)
		{
			dh[rr][l]=dh[rr][x]+1;
			bd3(l);
		}
		else if(dhh[l]==rr-1)
		{
			pr[ctd]=l;
		}
	}
}

int main()
{
	long long i,k,l,sz,p,mx;
	multiset<pair<long long,long long>>::iterator it;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	scanf("%lld",&sz);
	for(i=1;i<=n;i++)
	{
		nr[i]=inf;
		ls[i]=-1;
		dhh[i]=-inf;
	}
	for(i=0;i<sz;i++)
	{
		scanf("%lld",&k);
		q.push(k);
		nr[k]=0;
	}
	for(;!q.empty();)
	{
		k=q.front();
		q.pop();
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i];
			if(nr[l]>nr[k]+1)
			{
				q.push(l);
				nr[l]=nr[k]+1;
			}
		}
	}
	for(rr=0;rr<18;rr++)
	{
		for(i=1;i<=n;i++)
		{
			if(ls[i]<rr*3)
			{
				cr=i;
				bd(i);
				bd2(i);
				dhh[ctd]=rr;
				bd3(ctd);
				ls[ctd]=inf;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		mx=0;
		for(p=i;p;p=pr[p])
		{
			it=ms[p].lower_bound({-dh[dhh[p]][i],-inf});
			if(it!=ms[p].begin())
			{
				mx=max(mx,prev(it)->sc);
			}
		}
		printf("%lld%c",mx," \n"[i==n]);
	}
}