#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,cr,pr[100069];
pair<long long,long long> as[200069];
bitset<100069> vtd,sq;
vector<long long> al[100069];

inline void ad(long long x)
{
	if(!cr)
	{
		cr=x;
	}
	else
	{
		al[cr].push_back(x);
		al[x].push_back(cr);
		pr[cr]=x;
		pr[x]=cr;
		cr=0;
	}
}

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			sq[l]=!sq[x];
			dfs(l);
		}
	}
}

int main()
{
	long long i,k,l;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&k,&l);
		as[i*2-1]={k,i};
		as[i*2]={l+1,i};
	}
	sort(as+1,as+n*2+1);
	for(i=1;i<=n*2;i++)
	{
		k=as[i].sc;
		if(!vtd[k])
		{
			ad(k);
		}
		else
		{
			if(cr==k)
			{
				cr=0;
			}
			else
			{
				ad(pr[k]);
			}
		}
		vtd[k]=!vtd[k];
	}
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			dfs(i);
		}
		printf("%lld%c",(long long)sq[i]," \n"[i==n]);
	}
}