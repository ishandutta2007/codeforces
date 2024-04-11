#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,st,nr[200069],dsu[100069],inf=1e18;
pair<long long,long long> rg[100069];
priority_queue<pair<long long,pair<long long,long long>>> al[100069];
priority_queue<pair<long long,long long>> pq;

struct segtree
{
	long long l,r;
	pair<long long,long long> mxe;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		if(l==r)
		{
			mxe={-inf,l};
		}
		else
		{
			long long ii,md=(l+r)/2;
			
			mxe={-inf,n+1};
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
				mxe=max(mxe,p[ii]->mxe);
			}
		}
	}
	void ud(long long x,long long w)
	{
		if(l>x||r<x);
		else if(l>=x&&r<=x)
		{
			mxe.fr=w;
		}
		else
		{
			long long ii;
			
			mxe={-inf,n+1};
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(x,w);
				mxe=max(mxe,p[ii]->mxe);
			}
		}
	}
	pair<long long,long long> qr(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return {-inf,n+1};
		}
		else if(l>=lh&&r<=rh)
		{
			return mxe;
		}
		else
		{
			return max(p[0]->qr(lh,rh),p[1]->qr(lh,rh));
		}
	}
}
sg;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	long long i,ky,k,l,w,lb,rb,lb2,rb2,e,ww;
	pair<long long,long long> tmp;
	
	scanf("%lld%lld%lld",&n,&m,&st);
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&ky,&k,&l);
		if(ky==1)
		{
			lb=k;
			rb=k;
			lb2=l;
			rb2=l;
		}
		else if(ky==2)
		{
			scanf("%lld",&w);
			lb=k;
			rb=k;
			lb2=l;
			rb2=w;
		}
		else if(ky==3)
		{
			scanf("%lld",&w);
			lb=l;
			rb=w;
			lb2=k;
			rb2=k;
		}
		scanf("%lld",&w);
		al[lb].push({rb,{i,w}});
		rg[i]={lb2,rb2};
	}
	sg.bd(1,n);
	for(i=1;i<=n;i++)
	{
		al[i].push({-inf,{0,0}});
		sg.ud(i,al[i].top().fr);
	}
	for(i=1;i<=n+m;i++)
	{
		nr[i]=inf;
	}
	for(i=1;i<=n+1;i++)
	{
		dsu[i]=i;
	}
	pq.push({0,st});
	nr[st]=0;
	dsu[fd(st)]=fd(st+1);
	for(;!pq.empty();)
	{
		k=pq.top().sc;
		w=-pq.top().fr;
		pq.pop();
		if(w>nr[k])
		{
			continue;
		}
		if(k<=n)
		{
			for(;1;)
			{
				tmp=sg.qr(1,k);
				if(tmp.fr<k)
				{
					break;
				}
				e=tmp.sc;
				l=al[e].top().sc.fr;
				ww=al[e].top().sc.sc;
				al[e].pop();
				pq.push({-w-ww,n+l});
				nr[n+l]=w+ww;
				sg.ud(e,al[e].top().fr);
			}
		}
		else
		{
			lb=rg[k-n].fr;
			rb=rg[k-n].sc;
			for(i=fd(lb);i<=rb;i=fd(i+1))
			{
				pq.push({-w,i});
				nr[i]=w;
				dsu[fd(i)]=fd(i+1);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(nr[i]==inf)
		{
			nr[i]=-1;
		}
		printf("%lld%c",nr[i]," \n"[i==n]);
	}
}