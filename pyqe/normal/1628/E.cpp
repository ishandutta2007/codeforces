#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const int inf=1e9;
int n,nn=0,dsu[600069],al[600069][2],peu[600069],dh[600069],lg2[1200069];
pair<int,pair<int,int>> ed[300069];
pair<int,int> sp[20][1200069];

int fd(int x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void dfs(int x)
{
	int i,l;
	
	nn++;
	peu[x]=nn;
	sp[0][nn]={dh[x],x};
	for(i=0;i<2;i++)
	{
		l=al[x][i];
		if(l)
		{
			dh[l]=dh[x]+1;
			dfs(l);
			nn++;
			sp[0][nn]={dh[x],x};
		}
	}
}

inline void spbd()
{
	int i,j,k;
	
	for(i=1;1ll<<i<=nn;i++)
	{
		for(j=1;j<=nn+1-(1ll<<i);j++)
		{
			sp[i][j]=min(sp[i-1][j],sp[i-1][j+(1ll<<i-1)]);
		}
	}
	for(i=1;i<=nn;i++)
	{
		for(k=i;k>1;k/=2,lg2[i]++);
	}
}

inline int spqr(int lh,int rh)
{
	int e=lg2[rh-lh+1];
	
	return min(sp[e][lh],sp[e][rh+1-(1ll<<e)]).sc;
}

inline int lca(int x,int y)
{
	if(peu[x]>peu[y])
	{
		swap(x,y);
	}
	return spqr(peu[x],peu[y]);
}

inline int pth(int x,int y)
{
	int k=lca(x,y);
	
	if(k>n)
	{
		return ed[k-n].fr;
	}
	else
	{
		return -inf;
	}
}

struct val
{
	int l=-1,r,z=-inf;
};

struct segtree
{
	int l,r,mx,lz;
	val ans;
	segtree *p[2];
	
	inline val mrg(val x,val y)
	{
		if(x.l==-1)
		{
			return y;
		}
		else if(y.l==-1)
		{
			return x;
		}
		else
		{
			val tmp;
			
			tmp.l=x.l;
			tmp.r=y.r;
			tmp.z=max(max(x.z,y.z),pth(x.r,y.l));
			return tmp;
		}
	}
	void bd(int lh,int rh)
	{
		l=lh;
		r=rh;
		lz=-1;
		if(l==r)
		{
			mx=-inf;
		}
		else
		{
			int ii,md=(l+r)/2;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
			mx=max(max(p[0]->mx,p[1]->mx),pth(p[0]->r,p[1]->l));
		}
	}
	inline void ad(bool ky)
	{
		if(!ky)
		{
			ans.l=-1;
			ans.z=-inf;
		}
		else
		{
			ans.l=l;
			ans.r=r;
			ans.z=mx;
		}
		lz=ky;
	}
	inline void blc()
	{
		if(lz!=-1)
		{
			int ii;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ad(lz);
			}
			lz=-1;
		}
	}
	void ud(int lh,int rh,bool ky)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			ad(ky);
		}
		else
		{
			int ii;
			
			blc();
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(lh,rh,ky);
			}
			ans=mrg(p[0]->ans,p[1]->ans);
		}
	}
}
sg;

int main()
{
	int t,rr,i,ky,k,l,w,z;
	
	scanf("%d%d",&n,&t);
	for(i=1;i<=n-1;i++)
	{
		scanf("%d%d%d",&k,&l,&w);
		ed[i]={w,{k,l}};
	}
	sort(ed+1,ed+n);
	for(i=1;i<=n;i++)
	{
		dsu[i]=i;
	}
	for(i=1;i<=n-1;i++)
	{
		k=ed[i].sc.fr;
		l=ed[i].sc.sc;
		dsu[n+i]=n+i;
		al[n+i][0]=fd(k);
		al[n+i][1]=fd(l);
		dsu[fd(k)]=fd(n+i);
		dsu[fd(l)]=fd(n+i);
	}
	dfs(n*2-1);
	spbd();
	sg.bd(1,n);
	for(rr=0;rr<t;rr++)
	{
		scanf("%d%d",&ky,&k);
		if(ky==1)
		{
			scanf("%d",&l);
			sg.ud(k,l,1);
		}
		else if(ky==2)
		{
			scanf("%d",&l);
			sg.ud(k,l,0);
		}
		else
		{
			l=sg.ans.l;
			z=sg.ans.z;
			if(l!=-1)
			{
				z=max(z,pth(k,l));
			}
			if(z==-inf)
			{
				z=-1;
			}
			printf("%d\n",z);
		}
	}
}