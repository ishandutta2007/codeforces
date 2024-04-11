#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,pst[300069],cd[300069],dh[300069],c=0,cdh=0;
vector<long long> al[300069];
bitset<300069> vtd;
pair<long long,pair<long long,long long>> qq[300069];
queue<pair<long long,long long>> q;

long long md(long long l,long long r)
{
	return (l+r)/2;
}

struct segtree
{
	long long l,r,mn,lz;
	segtree *p1,*p2;
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		lz=0;
		if(lh==rh)
		{
			mn=0;
		}
		else
		{
			p1=new segtree;
			p2=new segtree;
			p1->bd(lh,md(lh,rh));
			p2->bd(md(lh,rh)+1,rh);
			mn=min(p1->mn,p2->mn);
		}
	}
	void blc()
	{
		p1->mn+=lz;
		p2->mn+=lz;
		p1->lz+=lz;
		p2->lz+=lz;
		lz=0;
	}
	void ud(long long lh,long long rh,long long w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			mn+=w;
			lz+=w;
		}
		else
		{
			blc();
			p1->ud(lh,rh,w);
			p2->ud(lh,rh,w);
			mn=min(p1->mn,p2->mn);
		}
	}
	long long qr(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return 1e18;
		}
		else if(l>=lh&&r<=rh)
		{
			return mn;
		}
		else
		{
			blc();
			return min(p1->qr(lh,rh),p2->qr(lh,rh));
		}
	}
}
sg;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	c++;
	pst[x]=c;
	dh[x]=cdh;
	cdh++;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			cd[x]+=cd[l]+1;
		}
	}
	cdh--;
}

int main()
{
	long long t,rr,i,j,k,l,w,sz,kk,ll;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	dfs(1);
	sg.bd(1,n);
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		qq[rr]={l+dh[k],{k,w}};
	}
	sort(qq,qq+t);
	vtd.reset();
	q.push({1,0});
	vtd[1]=1;
	for(j=0;!q.empty();)
	{
		k=q.front().fr;
		w=q.front().sc;
		q.pop();
		for(;j<t&&qq[j].fr<w;j++)
		{
			kk=qq[j].sc.fr;
			ll=qq[j].sc.sc;
			sg.ud(pst[kk],pst[kk]+cd[kk],ll);
		}
		sg.ud(pst[k],pst[k],-sg.qr(pst[k],pst[k]));
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i];
			if(!vtd[l])
			{
				q.push({l,w+1});
				vtd[l]=1;
			}
		}
	}
	for(;j<t;j++)
	{
		kk=qq[j].sc.fr;
		ll=qq[j].sc.sc;
		sg.ud(pst[kk],pst[kk]+cd[kk],ll);
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sg.qr(pst[i],pst[i])," \n"[i==n]);
	}
}