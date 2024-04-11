#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fi first
#define se second
const int L=1,R=1000000000;
int n,tot,ord,l,r,p,mid,ans;
long long v,nw;
set<pair<int,int> > s;
set<pair<int,int> >::iterator it;

struct node
{
	int ls,rs;
	long long val,lazk,lazb;
	bool laz; 
}t[6000001];

void pushdown(int i,int l,int r)
{
	if (!t[i].ls) t[i].ls=(++tot);
	if (!t[i].rs) t[i].rs=(++tot);
	if (!t[i].laz&&t[i].lazb==0) return;
	int mid=(l+r)>>1;
	if (t[i].laz)
	{
		t[t[i].ls].laz=t[t[i].rs].laz=1;
		t[t[i].ls].lazk=t[t[i].rs].lazk=t[i].lazk;
		t[t[i].ls].lazb=t[t[i].rs].lazb=t[i].lazb;
		if (t[i].lazk>0) t[t[i].ls].val=1ll*l*t[i].lazk+t[i].lazb,t[t[i].rs].val=1ll*(mid+1)*t[i].lazk+t[i].lazb;
		else t[t[i].ls].val=1ll*mid*t[i].lazk+t[i].lazb,t[t[i].rs].val=1ll*r*t[i].lazk+t[i].lazb;
		t[i].laz=0; t[i].lazk=t[i].lazb=0; return;
	}
	t[t[i].ls].val+=t[i].lazb; t[t[i].rs].val+=t[i].lazb;
	t[t[i].ls].lazb+=t[i].lazb; t[t[i].rs].lazb+=t[i].lazb;
	t[i].lazb=0;
}

long long getmin(long long a,long long b) {return a<b?a:b;}

void add(int i,int l,int r,int ql,int qr,long long v)
{
	if (ql>qr) return;
	if (l==ql&&r==qr) {t[i].val+=v,t[i].lazb+=v; return;}
	pushdown(i,l,r); int mid=(l+r)>>1;
	if (qr<=mid) add(t[i].ls,l,mid,ql,qr,v); else
	if (ql>mid) add(t[i].rs,mid+1,r,ql,qr,v); else
	add(t[i].ls,l,mid,ql,mid,v),add(t[i].rs,mid+1,r,mid+1,qr,v);
	t[i].val=getmin(t[t[i].ls].val,t[t[i].rs].val);
}

void change(int i,int l,int r,int ql,int qr,long long k,long long b)
{
	if (ql>qr) return;
	if (l==ql&&r==qr) 
	{
		if (k>0) t[i].val=k*l+b; else t[i].val=k*r+b;
		t[i].laz=1; t[i].lazk=k; t[i].lazb=b; return;
	}
	pushdown(i,l,r); int mid=(l+r)>>1;
	if (qr<=mid) change(t[i].ls,l,mid,ql,qr,k,b); else
	if (ql>mid) change(t[i].rs,mid+1,r,ql,qr,k,b); else
	change(t[i].ls,l,mid,ql,mid,k,b),change(t[i].rs,mid+1,r,mid+1,qr,k,b);
	t[i].val=getmin(t[t[i].ls].val,t[t[i].rs].val);
}

long long query(int i,int l,int r,int ql,int qr)
{
	if (ql>qr) return 0;
	if (ql==l&&qr==r) return t[i].val;
	int mid=(l+r)>>1;
	if (t[i].laz) 
	{
		if (t[i].lazk>0) return t[i].lazk*ql+t[i].lazb;
		else return t[i].lazk*qr+t[i].lazb;
	}
	if (qr<=mid)
	{
		if (!t[i].ls) return t[i].lazb;
		return query(t[i].ls,l,mid,ql,qr)+t[i].lazb;
	}
	if (ql>mid)
	{
		if (!t[i].rs) return t[i].lazb;
		return query(t[i].rs,mid+1,r,ql,qr)+t[i].lazb;
	}
	long long ansl,ansr;
	if (t[i].ls) ansl=query(t[i].ls,l,mid,ql,mid); else ansl=0;
	if (t[i].rs) ansr=query(t[i].rs,mid+1,r,mid+1,qr); else ansr=0;
	return getmin(ansl,ansr)+t[i].lazb;
}

int main()
{
	s.clear(); s.insert(mp(0,0)); s.insert(mp(1000000001,0));
	scanf("%d",&n); tot=1;
	while (n--)
	{
		scanf("%d",&ord);
		if (ord==1) 
		{
			scanf("%d%I64d",&p,&v);
			it=s.lower_bound(mp(p,-1000000001)); r=(*it).fi; it--;
			if (p==1) nw=0; else nw=query(1,L,R,p-1,p-1);
			change(1,L,R,p,r-1,v,v*(1-p)+nw);
			add(1,L,R,r,R,1ll*(r-p)*(v-(*it).se));
			s.insert(mp(p,v));
		} else
		if (ord==2)
		{
			scanf("%d",&p);
			it=s.lower_bound(mp(p,-1000000001));
			it--; l=(*it).se; it++; it++; r=(*it).fi; it--;
			if (p==1) nw=0; else nw=query(1,L,R,p-1,p-1);
			change(1,L,R,p,r-1,l,1ll*l*(1-p)+nw);
			add(1,L,R,r,R,1ll*(r-p)*(l-(*it).se));
			s.erase(mp(p,(*it).se));
		} else
		{
			scanf("%d%d%I64d",&l,&r,&v); int lll=l;
			if (v==0) {printf("%d\n",l); continue;}
			if (l==r) {puts("-1"); continue;} r--;
			it=s.lower_bound(mp(l,-1000000001)); bool bo=0;
			if ((*it).fi!=l)
			{
				p=l; long long v=0; bo=1;
				it=s.lower_bound(mp(p,-1000000001)); int r=(*it).fi; it--;
				if (p==1) nw=0; else nw=query(1,L,R,p-1,p-1);
				change(1,L,R,p,r-1,v,v*(1-p)+nw);
				add(1,L,R,r,R,1ll*(r-p)*(v-(*it).se));
				s.insert(mp(p,v));
			}
			if (l>1) v=query(1,L,R,l-1,l-1)-v; else v=-v;
			ans=-2; 
			while (l<=r)
			{
				mid=(l+r)>>1;
				if (query(1,L,R,lll,mid)<=v) ans=mid,r=mid-1; else l=mid+1;
			}
			if (ans==-2) puts("-1"); else
			{
				nw=query(1,L,R,ans,ans);
				it=s.lower_bound(mp(ans,-1000000001)); if ((*it).fi!=ans) it--;
				printf("%.6lf\n",ans+1.0*(v-nw)/(1.0*(*it).se)+1);
			}
			if (bo)
			{
				p=lll;
				it=s.lower_bound(mp(p,-1000000001));
				it--; l=(*it).se; it++; it++; r=(*it).fi; it--;
				if (p==1) nw=0; else nw=query(1,L,R,p-1,p-1);
				change(1,L,R,p,r-1,l,1ll*l*(1-p)+nw);
				add(1,L,R,r,R,1ll*(r-p)*(l-(*it).se));
				s.erase(mp(p,(*it).se));
			}
		}
	}
	return 0;
}