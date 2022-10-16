#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

int n,vl[2000069],udn[1000069],ps[1000069];
long long uds[2000069];
pair<pair<int,int>,pair<int,int>> qq[1000069];

struct segtree
{
	int l,r,kd,ls,lz,lbz,rbz;
	long long wg,lz2;
	segtree *p[2];
	
	void bd(int lh,int rh)
	{
		l=lh;
		r=rh;
		wg=0;
		kd=l==r;
		ls=0;
		lz=0;
		lz2=0;
		lbz=0;
		rbz=0;
		if(l<r)
		{
			int ii,md=(l+r)/2;
			
			for(ii=0;ii<2;ii++)
			{
				p[ii]=new segtree;
				p[ii]->bd(!ii?l:md+1,!ii?md:r);
			}
		}
	}
	inline void chk()
	{
		if(kd)
		{
			wg+=uds[ps[kd-1]+1+udn[kd]]-uds[ps[kd-1]+1+ls];
			ls=udn[kd];
		}
		if(lz)
		{
			lz2+=uds[ps[lz-1]+1+udn[lz]]-uds[ps[lz-1]+1+rbz];
			rbz=udn[lz];
		}
	}
	inline void ad(int w,long long w2,int lb,int rb)
	{
		if(kd)
		{
			wg+=w2;
		}
		lz2+=w2;
		if(w)
		{
			if(kd)
			{
				wg+=uds[lower_bound(vl+ps[kd-1]+1,vl+ps[kd-1]+2+udn[kd],lb)-vl-1]-uds[ps[kd-1]+1+ls];
				kd=w;
				ls=rb;
			}
			if(lz)
			{
				lz2+=uds[lower_bound(vl+ps[lz-1]+1,vl+ps[lz-1]+2+udn[lz],lb)-vl-1]-uds[ps[lz-1]+1+rbz];
			}
			else
			{
				lbz=lb;
			}
			lz=w;
			rbz=rb;
		}
	}
	inline void blc()
	{
		int ii;
		
		for(ii=0;ii<2;ii++)
		{
			p[ii]->ad(lz,lz2,lbz,rbz);
		}
		lz=0;
		lz2=0;
	}
	void ud(int lh,int rh,int w,int rr)
	{
		chk();
		if(l>rh||r<lh);
		else if(l>=lh&&r<=rh)
		{
			ad(w,0,rr,udn[w]);
		}
		else
		{
			int ii;
			
			blc();
			for(ii=0;ii<2;ii++)
			{
				p[ii]->ud(lh,rh,w,rr);
			}
		}
	}
	long long qr(int x)
	{
		chk();
		if(l>x||r<x)
		{
			return 0;
		}
		else if(l>=x&&r<=x)
		{
			return wg;
		}
		else
		{
			blc();
			return p[0]->qr(x)+p[1]->qr(x);
		}
	}
}
sg;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,rr,i,ky,k,l,w;
	string s;
	
	cin>>n>>t;
	for(rr=1;rr<=t;rr++)
	{
		cin>>s;
		if(s[0]=='C')
		{
			cin>>k>>l>>w;
			qq[rr]={{0,k},{l,w}};
		}
		else if(s[0]=='A')
		{
			cin>>k>>l;
			qq[rr]={{1,k},{l,0}};
			udn[k]++;
		}
		else
		{
			cin>>k;
			qq[rr]={{2,k},{0,0}};
		}
	}
	for(i=1;i<=n;i++)
	{
		ps[i]=ps[i-1]+udn[i]+1;
		udn[i]=0;
	}
	sg.bd(1,n);
	for(rr=1;rr<=t;rr++)
	{
		ky=qq[rr].fr.fr;
		k=qq[rr].fr.sc;
		l=qq[rr].sc.fr;
		w=qq[rr].sc.sc;
		if(!ky)
		{
			sg.ud(k,l,w,rr);
		}
		else if(ky==1)
		{
			udn[k]++;
			uds[ps[k-1]+1+udn[k]]=uds[ps[k-1]+udn[k]]+l;
			vl[ps[k-1]+1+udn[k]]=rr;
		}
		else
		{
			cout<<sg.qr(k)<<"\n";
		}
	}
}