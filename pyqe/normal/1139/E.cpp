#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nn=0,a[5069],cl[5069],qq[5069],wg[20069],sq[5069],mn;
bitset<5069> alr;
vector<pair<long long,long long>> al[10069];
map<pair<long long,long long>,bool> ve;
bitset<10069> vtd;
stack<long long> sk;
bool r0;

void ae(long long x,long long y,long long w)
{
	if(!ve[{x,y}])
	{
		wg[nn+(y<x)]=w;
		al[x].push_back({y,nn+(y<x)});
		al[y].push_back({x,nn+(x<y)});
		nn+=2;
		ve[{x,y}]=1;
		ve[{y,x}]=1;
	}
}

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,p;
	
	vtd[x]=1;
	if(x==10001)
	{
		r0=1;
		mn=sk.top();
		return;
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		p=al[x][i].sc;
		if(!vtd[l]&&wg[p])
		{
			sk.push(min(sk.top(),wg[p]));
			dfs(l);
			sk.pop();
			if(r0)
			{
				wg[p]-=mn;
				wg[p/2*2+!(p%2)]+=mn;
				return;
			}
		}
	}
}

int main()
{
	long long t,rr,i,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",cl+i);
	}
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld",qq+rr);
		alr[qq[rr]]=1;
	}
	for(i=1;i<=m;i++)
	{
		ae(5000+i,10001,1);
	}
	for(i=1;i<=n;i++)
	{
		if(!alr[i])
		{
			ae(a[i],5000+cl[i],1);
		}
	}
	sk.push(1e18);
	for(rr=t;rr;rr--)
	{
		for(;z<5000;z++)
		{
			r0=0;
			vtd.reset();
			dfs(z);
			if(!r0)
			{
				break;
			}
		}
		sq[rr]=z;
		ae(a[qq[rr]],5000+cl[qq[rr]],1);
	}
	for(rr=1;rr<=t;rr++)
	{
		printf("%lld\n",sq[rr]);
	}
}