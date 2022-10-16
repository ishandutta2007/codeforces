#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,dsu[200069],dh[200069],ds[200069],gd[200069];
vector<pair<long long,long long>> al[200069];
bitset<200069> vtd,vtd2;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		fd(dsu[x]);
		ds[x]+=ds[dsu[x]];
		if(gd[dsu[dsu[x]]]);
		{
			ds[x]%=gd[dsu[dsu[x]]];
		}
		dsu[x]=dsu[dsu[x]];
	}
	return dsu[x];
}

void dfs(long long x)
{
	long long i,sz=al[x].size(),k,l,w,ww,w3,tg;
	
	vtd[x]=1;
	vtd2[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(!vtd[l])
		{
			dh[l]=dh[x]+w;
			dfs(l);
		}
		if(vtd2[fd(l)])
		{
			k=fd(x);
			tg=fd(l);
			ww=dh[x]-dh[k]+w+ds[l];
			if(gd[tg])
			{
				ww%=gd[tg];
			}
			w3=dh[k]-dh[tg]+ww;
			if(gd[tg])
			{
				w3=(w3%gd[tg]+gd[tg])%gd[tg];
			}
			gd[tg]=__gcd(gd[tg],w3);
			if(dh[fd(l)]<=dh[fd(x)]&&fd(l)!=k)
			{
				ds[k]=ww;
				gd[tg]=__gcd(gd[tg],gd[k]);
				dsu[k]=tg;
			}
		}
	}
	vtd2[x]=0;
}

int main()
{
	long long t,rr,i,k,l,w,ww;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		al[k].push_back({l,w});
	}
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
	}
	dh[1]=0;
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			dfs(i);
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		ww=gd[fd(k)];
		if((!ww&&!l)||(ww&&(w-l)%__gcd(ww,w)==0))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}