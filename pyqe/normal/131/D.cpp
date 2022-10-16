#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,sk[100069],pst[100069],nr[100069],inf=1e18;
vector<pair<long long,long long>> al[100069];
bitset<100069> vtd;
bool r0=0;
queue<long long> q;

void dfs(long long x,long long b4)
{
	long long i,j,sz=al[x].size(),l,p;
	
	vtd[x]=1;
	nn++;
	sk[nn]=x;
	pst[x]=nn;
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
			dfs(l,p);
			if(r0)
			{
				return;
			}
		}
		else
		{
			for(j=pst[l];j<=nn;j++)
			{
				q.push(sk[j]);
				nr[sk[j]]=0;
			}
			r0=1;
			return;
		}
	}
	nn--;
}

int main()
{
	long long i,k,l,w,sz;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back({l,i});
		al[l].push_back({k,i});
		nr[i]=inf;
	}
	dfs(1,0);
	for(;!q.empty();)
	{
		k=q.front();
		w=nr[k];
		q.pop();
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i].fr;
			if(w+1<nr[l])
			{
				q.push(l);
				nr[l]=w+1;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",nr[i]," \n"[i==n]);
	}
}