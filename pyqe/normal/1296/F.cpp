#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nn=0,cr,cw,mn,sk[5069],sq[5069];
vector<pair<long long,long long>> al[5069];
pair<pair<long long,long long>,long long> qq[5069];
bitset<5069> vtd;
bool r0;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,p;
	
	vtd[x]=1;
	if(x==cr)
	{
		r0=1;
		return;
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		p=al[x][i].sc;
		if(!vtd[l])
		{
			dfs(l);
			if(r0)
			{
				sq[p]=max(sq[p],cw);
				return;
			}
		}
	}
}

void chk(long long x)
{
	long long i,sz=al[x].size(),l,p;
	
	vtd[x]=1;
	if(x==cr)
	{
		mn=sk[nn];
		r0=1;
		return;
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		p=al[x][i].sc;
		if(!vtd[l])
		{
			nn++;
			sk[nn]=min(sk[nn-1],sq[p]);
			chk(l);
			nn--;
			if(r0)
			{
				return;
			}
		}
	}
}

int main()
{
	long long i,k,l,w;
	
	scanf("%lld",&n);
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back({l,i});
		al[l].push_back({k,i});
		sq[i]=1;
	}
	scanf("%lld",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		qq[i]={{k,l},w};
		vtd.reset();
		r0=0;
		cr=l;
		cw=w;
		dfs(k);
	}
	sk[0]=1e18;
	for(i=1;i<=m;i++)
	{
		k=qq[i].fr.fr;
		l=qq[i].fr.sc;
		w=qq[i].sc;
		vtd.reset();
		r0=0;
		cr=l;
		chk(k);
		if(mn!=w)
		{
			printf("-1\n");
			return 0;
		}
	}
	for(i=1;i<=n-1;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n-1]);
	}
}