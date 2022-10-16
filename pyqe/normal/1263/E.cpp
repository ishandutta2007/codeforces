#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,p=1,a[1000069];

long long md(long long l,long long r)
{
	return (l+r)/2;
}

struct segtree
{
	long long l,r,lz;
	pair<long long,long long> ans;
	segtree *p1,*p2;
	
	pair<long long,long long> mrg(pair<long long,long long> x,pair<long long,long long> y)
	{
		return {min(x.fr,y.fr),max(x.sc,y.sc)};
	}
	void bd(long long lh,long long rh)
	{
		l=lh;
		r=rh;
		lz=0;
		if(l==r)
		{
			ans={0,0};
		}
		else
		{
			p1=new segtree;
			p2=new segtree;
			p1->bd(l,md(l,r));
			p2->bd(md(l,r)+1,r);
			ans=mrg(p1->ans,p2->ans);
		}
	}
	void blc()
	{
		p1->ans.fr+=lz;
		p2->ans.fr+=lz;
		p1->ans.sc+=lz;
		p2->ans.sc+=lz;
		p1->lz+=lz;
		p2->lz+=lz;
		lz=0;
	}
	void ud(long long lh,long long rh,long long w)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			ans.fr+=w;
			ans.sc+=w;
			lz+=w;
		}
		else
		{
			blc();
			p1->ud(lh,rh,w);
			p2->ud(lh,rh,w);
			ans=mrg(p1->ans,p2->ans);
		}
	}
}
sg;

int main()
{
	long long i,k,ttl=0;
	char ch;
	
	scanf("%lld",&n);
	sg.bd(1,n);
	for(i=0;i<n;i++)
	{
		scanf(" %c",&ch);
		if(ch=='L')
		{
			p=max(p-1,1ll);
		}
		else if(ch=='R')
		{
			p++;
		}
		else
		{
			if(ch=='(')
			{
				k=1;
			}
			else if(ch==')')
			{
				k=-1;
			}
			else
			{
				k=0;
			}
			sg.ud(p,n,k-a[p]);
			ttl+=k-a[p];
			a[p]=k;
		}
		if(ttl!=0||sg.ans.fr<0)
		{
			printf("-1");
		}
		else
		{
			printf("%lld",sg.ans.sc);
		}
		printf("%c"," \n"[i==n-1]);
	}
}