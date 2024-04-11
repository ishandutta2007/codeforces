#include <bits/stdc++.h>

using namespace std;

long long n,pst[200069],sbt[200069];
vector<long long> al[200069];
bitset<200069> a,as;

long long av(long long x,long long y)
{
	return (x+y)/2;
}

struct segtree
{
	long long l,r,sm;
	bool lz=0;
	segtree *p[2];
	
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		if(l==r)
		{
			sm=as[l];
		}
		else
		{
			long long ii;
			
			sm=0;
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:av(l,r)+1,!ii?av(l,r):r);
				sm+=p[ii]->sm;
			}
		}
	}
	void blc()
	{
		if(lz)
		{
			long long ii;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]->sm=p[ii]->r-p[ii]->l+1-p[ii]->sm;
				p[ii]->lz^=1;
			}
		}
		lz=0;
	}
	void ud(long long lh,long long rh)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			sm=r-l+1-sm;
			lz^=1;
		}
		else
		{
			long long ii;
			
			blc();
			sm=0;
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(lh,rh);
				sm+=p[ii]->sm;
			}
		}
	}
	long long qr(long long lh,long long rh)
	{
		if(l>rh||r<lh)
		{
			return 0;
		}
		else if(l>=lh&&r<=rh)
		{
			return sm;
		}
		else
		{
			blc();
			return p[0]->qr(lh,rh)+p[1]->qr(lh,rh);
		}
	}
}
sg;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	n++;
	as[n]=a[x];
	pst[x]=n;
	sbt[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		dfs(l);
		sbt[x]+=sbt[l];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long t,rr,i,k;
	string s;
	
	cin>>n;
	for(i=2;i<=n;i++)
	{
		cin>>k;
		al[k].push_back(i);
	}
	for(i=1;i<=n;i++)
	{
		cin>>k;
		a[i]=k;
	}
	n=0;
	dfs(1);
	sg.bd(1,n);
	cin>>t;
	for(rr=0;rr<t;rr++)
	{
		cin>>s>>k;
		if(s[0]=='p')
		{
			sg.ud(pst[k],pst[k]+sbt[k]-1);
		}
		else
		{
			cout<<sg.qr(pst[k],pst[k]+sbt[k]-1)<<"\n";
		}
	}
}