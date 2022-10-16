#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

int n,d,inf=1e9;
multiset<pair<int,int>> ms;
multiset<pair<int,int>>::iterator it;

struct segtree
{
	int l,r,lz;
	pair<int,int> z;
	segtree *p[2];
	
	pair<int,int> mrg(pair<int,int> x,pair<int,int> y)
	{
		return {min(x.fr,y.fr),max(x.sc,y.sc)};
	}
	void bd(int lh,int rh)
	{
		l=lh;
		r=rh;
		lz=0;
		if(l==r)
		{
			z={0,0};
		}
		else
		{
			int ii,md=(l+r)/2;
			
			z={inf,-inf};
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
				z=mrg(z,p[ii]->z);
			}
		}
	}
	void blc()
	{
		int ii;
		
		for(ii=0;ii<2;ii++)
		{
			p[ii]->z.fr+=lz;
			p[ii]->z.sc+=lz;
			p[ii]->lz+=lz;
		}
		lz=0;
	}
	void ud(int lh,int rh,int w)
	{
		if(lh>rh||l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			z.fr+=w;
			z.sc+=w;
			lz+=w;
		}
		else
		{
			int ii;
			
			blc();
			z={inf,-inf};
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(lh,rh,w);
				z=mrg(z,p[ii]->z);
			}
		}
	}
	pair<int,int> qr(int lh,int rh)
	{
		if(l>rh||r<lh)
		{
			return {inf,-inf};
		}
		else if(l>=lh&&r<=rh)
		{
			return z;
		}
		else
		{
			blc();
			return mrg(p[0]->qr(lh,rh),p[1]->qr(lh,rh));
		}
	}
}
sg;

int main()
{
	int t,rr,i,y,x,e,lh,rh,md,zz;
	pair<int,int> tmp;
	
	scanf("%d%d%d",&n,&d,&t);
	sg.bd(1,n*2+t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%d%d",&y,&x);
		x+=abs(y-d);
		it=ms.find({y,x});
		e=it!=ms.end();
		for(lh=0,rh=t;lh<=rh;)
		{
			md=(lh+rh)/2;
			tmp=sg.qr(x,x+md);
			if(tmp.fr<=e)
			{
				zz=md;
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		if(!e)
		{
			ms.insert({y,x});
			sg.ud(x,x+zz,1);
		}
		else
		{
			ms.erase(it);
			sg.ud(x,x+zz,-1);
		}
		zz=0;
		for(lh=1,rh=n+t;lh<=rh;)
		{
			md=(lh+rh)/2;
			tmp=sg.qr(n+md,n*2+t);
			if(tmp.sc)
			{
				zz=md;
				lh=md+1;
			}
			else
			{
				rh=md-1;
			}
		}
		printf("%d\n",zz);
	}
}