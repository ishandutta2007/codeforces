#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

int n,ma=2e5,nn[200069],pwk,dv=1e9+7,inf=1e9;
vector<pair<int,int>> fz[200069],sk[200069];

struct segtree
{
	int l,r,sm,od;
	segtree *p[2];
	
	void bd(int lh,int rh)
	{
		l=lh;
		r=rh;
		sm=1;
		od=0;
		if(l!=r)
		{
			int ii,md=(l+r)/2;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
		}
	}
	void ud(int x,int w)
	{
		if(l>=x&&r<=x)
		{
			sm=(long long)sm*w%dv;
		}
		else
		{
			int ii;
			segtree *tmp;
			
			for(ii=0;ii<2;ii++)
			{
				if(!(p[ii]->l>x||p[ii]->r<x))
				{
					if(p[ii]->od<od)
					{
						tmp=p[ii];
						p[ii]=new segtree;
						*p[ii]=*tmp;
						p[ii]->od=od;
					}
					p[ii]->ud(x,w);
				}
			}
			sm=(long long)p[0]->sm*p[1]->sm%dv;
		}
	}
	int qr(int lh,int rh)
	{
		if(l>rh||r<lh)
		{
			return 1;
		}
		else if(l>=lh&&r<=rh)
		{
			return sm;
		}
		else
		{
			return (long long)p[0]->qr(lh,rh)*p[1]->qr(lh,rh)%dv;
		}
	}
}
sg[100069];

int pw(int x,int y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=(long long)pwk*pwk%dv;
	if(y%2)
	{
		pwk=(long long)pwk*x%dv;
	}
	return pwk;
}

int main()
{
	int t,rr,i,j,k,l,w,sz,ww,c,z,zl=0;
	
	for(i=2;i<=ma;i++)
	{
		if(fz[i].empty())
		{
			for(j=i;j<=ma;j+=i)
			{
				for(c=0,k=j;k%i==0;k/=i,c++);
				fz[j].push_back({i,c});
			}
		}
	}
	scanf("%d",&n);
	sg[0].bd(1,n);
	for(i=1;i<=ma;i++)
	{
		sk[i].push_back({0,inf});
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		sg[i]=sg[i-1];
		sg[i].od=i;
		sz=fz[k].size();
		for(j=0;j<sz;j++)
		{
			l=fz[k][j].fr;
			w=fz[k][j].sc;
			for(c=w;nn[l]&&c;sk[l].pop_back(),nn[l]--)
			{
				ww=min(sk[l][nn[l]].sc,c);
				sk[l][nn[l]].sc-=ww;
				c-=ww;
				sg[i].ud(sk[l][nn[l]].fr,pw(l,dv-1-ww));
				if(sk[l][nn[l]].sc)
				{
					break;
				}
			}
			sk[l].push_back({i,w});
			nn[l]++;
			sg[i].ud(i,pw(l,w));
		}
	}
	scanf("%d",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%d%d",&k,&l);
		k=(k+zl)%n+1;
		l=(l+zl)%n+1;
		if(k>l)
		{
			swap(k,l);
		}
		z=sg[l].qr(k,l);
		printf("%d\n",z);
		zl=z;
	}
}