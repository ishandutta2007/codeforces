#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,dh[100069],cdh=0,pst[100069],sp[18][200069],lg2[200069];
vector<long long> al[100069];

struct val
{
	pair<long long,long long> mn[2],mx[2];
}
v0;

struct segtree
{
	long long l,r;
	val ans;
	segtree *p[2];
	
	val mrg(val x,val y)
	{
		val tmp;
		
		tmp.mn[0]=min(x.mn[0],y.mn[0]);
		tmp.mn[1]=min(max(x.mn[0],y.mn[0]),min(x.mn[1],y.mn[1]));
		tmp.mx[0]=max(x.mx[0],y.mx[0]);
		tmp.mx[1]=max(min(x.mx[0],y.mx[0]),max(x.mx[1],y.mx[1]));
		return tmp;
	}
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		if(l==r)
		{
			ans.mn[0]={pst[l],l};
			ans.mn[1]={1e18,-1};
			ans.mx[0]={pst[l],l};
			ans.mx[1]={-1e18,-1};
		}
		else
		{
			long long ii,md=(l+r)/2;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
			ans=mrg(p[0]->ans,p[1]->ans);
		}
	}
	val qr(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return v0;
		}
		else if(l>=lh&&r<=rh)
		{
			return ans;
		}
		else
		{
			return mrg(p[0]->qr(lh,rh),p[1]->qr(lh,rh));
		}
	}
}
sg;

void eut(long long x)
{
	long long i,sz=al[x].size(),l;
	
	dh[x]=cdh;
	nn++;
	sp[0][nn]=dh[x];
	pst[x]=nn;
	cdh++;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		eut(l);
		nn++;
		sp[0][nn]=dh[x];
		
	}
	cdh--;
}

long long qr(long long lh,long long rh)
{
	long long ln=rh-lh+1;
	
	return min(sp[lg2[ln]][lh],sp[lg2[ln]][rh-(1<<lg2[ln])+1]);
}

int main()
{
	long long t,rr,i,j,ii,k,l,mx,e;
	val tmp;
	pair<long long,long long> mxe;
	
	for(ii=0;ii<2;ii++)
	{
		v0.mn[ii]={1e18,-1};
		v0.mx[ii]={-1e18,-1};
	}
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n*2;i++)
	{
		for(k=i;k>1;k/=2,lg2[i]++);
	}
	for(i=2;i<=n;i++)
	{
		scanf("%lld",&k);
		al[k].push_back(i);
	}
	eut(1);
	for(i=1;i<18;i++)
	{
		for(j=1;j<=nn-(1<<i)+1;j++)
		{
			sp[i][j]=min(sp[i-1][j],sp[i-1][j+(1<<i-1)]);
		}
	}
	sg.bd(1,n);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		tmp=sg.qr(k,l);
		mxe=max(mp(qr(tmp.mn[0].fr,tmp.mx[1].fr),tmp.mx[0].sc),{qr(tmp.mn[1].fr,tmp.mx[0].fr),tmp.mn[0].sc});
		mx=mxe.fr;
		e=mxe.sc;
		printf("%lld %lld\n",e,mx);
	}
}