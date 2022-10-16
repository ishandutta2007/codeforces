#include <bits/stdc++.h>

using namespace std;

int n,lh,rh,d[1000069],pv;
bitset<1000069> a;

struct val
{
	int mn,mx,dl;
	
	void ud1(int w)
	{
		mn+=w;
		mx+=w;
		dl+=w;
	}
	void ud2(int w)
	{
		swap(mn,mx);
		mn=2*w-mn;
		mx=2*w-mx;
		dl=2*w-dl;
	}
}
val0;

val mrg(val x,val y)
{
	val ans;
	
	ans.mn=min(x.mn,y.mn);
	ans.mx=max(x.mx,y.mx);
	ans.dl=x.dl;
	return ans;
}

int md(int l,int r)
{
	return (l+r)/2;
}

struct segtree
{
	int l,r,lz;
	bool flp;
	val ans;
	segtree *p1,*p2;
	
	void bd(int lh,int rh)
	{
		l=lh;
		r=rh;
		lz=0;
		flp=0;
		if(l==r)
		{
			ans.mn=d[l];
			ans.mx=d[l];
			ans.dl=d[max(l-1,(int)0)];
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
		if(flp)
		{
			p1->ans.ud2(lz);
			p2->ans.ud2(lz);
			p1->lz=lz-p1->lz;
			p2->lz=lz-p2->lz;
		}
		else
		{
			p1->ans.ud1(2*lz);
			p2->ans.ud1(2*lz);
			p1->lz=lz+p1->lz;
			p2->lz=lz+p2->lz;
		}
		p1->flp^=flp;
		p2->flp^=flp;
		lz=0;
		flp=0;
	}
	void ud(int lh)
	{
		if(r<lh);
		else if(l>=lh)
		{
			if(pv==-1000000000)
			{
				pv=ans.dl;
			}
			ans.ud2(pv);
			lz=pv-lz;
			flp^=1;
		}
		else
		{
			blc();
			p1->ud(lh);
			p2->ud(lh);
			ans=mrg(p1->ans,p2->ans);
		}
	}
	int sm()
	{
		return ans.mx;
	}
}
sg;

struct segtree2
{
	int l,r,ans;
	bool flp;
	segtree2 *p1,*p2;
	
	void bd(int lh,int rh)
	{
		l=lh;
		r=rh;
		flp=0;
		if(l==r)
		{
			ans=a[l];
		}
		else
		{
			p1=new segtree2;
			p2=new segtree2;
			p1->bd(l,md(l,r));
			p2->bd(md(l,r)+1,r);
			ans=p1->ans+p2->ans;
		}
	}
	void blc()
	{
		if(flp)
		{
			p1->ans=p1->r-p1->l+1-p1->ans;
			p2->ans=p2->r-p2->l+1-p2->ans;
		}
		p1->flp^=flp;
		p2->flp^=flp;
		flp=0;
	}
	void ud(int lh,int rh)
	{
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			ans=r-l+1-ans;
			flp^=1;
		}
		else
		{
			blc();
			p1->ud(lh,rh);
			p2->ud(lh,rh);
			ans=p1->ans+p2->ans;
		}
	}
	int sm()
	{
		return ans;
	}
}
sg2;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i,t,rr,lh,rh;
	string s;
	
	cin>>n>>t>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=(s[i-1]-'0')/7;
	}
	for(i=1;i<=n;i++)
	{
		d[i]=d[i-1]-(a[i]*2-1);
	}
	sg.bd(0,n);
	sg2.bd(1,n);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		if(s[0]=='s')
		{
			cin>>lh>>rh;
			pv=-1e9;
			sg.ud(lh);
			pv=-1e9;
			sg.ud(rh+1);
			sg2.ud(lh,rh);
		}
		else
		{
			cout<<sg.sm()+sg2.sm()<<"\n";
		}
	}
}