#include<bits/stdc++.h>
using namespace std;

int n,m,q,ord,x,y,a[500010],b[500010];
set<pair<int,int> > s1,s2;

pair<long long,int> operator +(pair<long long,int> A,pair<long long,int> B) {return make_pair(A.first+B.first,A.second+B.second);}

struct node
{
	int val[4000010];
	long long sum[4000010];
	void add(int i,int l,int r,int x,int v)
	{
		val[i]+=v,sum[i]+=v*x;
		if (l==r) return;
		int mid=(l+r)>>1;
		if (x<=mid) add(i<<1,l,mid,x,v);
		else add(i<<1|1,mid+1,r,x,v);
	}
	void add(int x) {add(1,0,1000000,x,1);}
	void del(int x) {add(1,0,1000000,x,-1);}
	pair<long long,int> query(int i,int l,int r,int ql,int qr)
	{
		if (l==ql&&r==qr) return make_pair(sum[i],val[i]);
		int mid=(l+r)>>1;
		if (qr<=mid) return query(i<<1,l,mid,ql,qr);
		if (ql>mid) return query(i<<1|1,mid+1,r,ql,qr);
		return query(i<<1,l,mid,ql,mid)+query(i<<1|1,mid+1,r,mid+1,qr);
	}
	long long getans(int x)
	{
		pair<long long,int> s=query(1,0,1000000,max(x,0),1000000);
		return s.first-1ll*s.second*x;
	}
}t1,t2;

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),s1.insert(make_pair(a[i],i)),t1.add(a[i]);
	for (int i=1; i<=m; i++) scanf("%d",&b[i]),s2.insert(make_pair(b[i],i)),t2.add(b[i]);
	multiset<int>::iterator itt;
	while (q--)
	{
		scanf("%d",&ord);
		if (ord==1)
		{
			scanf("%d%d",&x,&y);
			s1.erase(make_pair(a[x],x));
			t1.del(a[x]);
			a[x]=y;
			s1.insert(make_pair(a[x],x));
			t1.add(a[x]);
		} else
		if (ord==2)
		{
			scanf("%d%d",&x,&y);
			s2.erase(make_pair(b[x],x));
			t2.del(b[x]);
			b[x]=y;
			s2.insert(make_pair(b[x],x));
			t2.add(b[x]);
		} else
		{
			scanf("%d",&x);
			int mi1=(*s1.begin()).first,mi2=(*s2.begin()).first,ma2=(*(--s2.end())).first;
			long long ans=t1.getans(min(min(ma2-x,mi2),mi1))-t2.getans(ma2-x);
			if (n>m&&mi1-x<=mi2) ans=max(ans,t1.getans(mi1-x)-t2.getans(mi1-x));
			if (n>m&&mi2-x<=mi1) ans=max(ans,t1.getans(mi2-x)-t2.getans(mi2-x));
			set<pair<int,int> >::iterator it=s1.lower_bound(make_pair(ma2+x,0));
			if (it!=s1.end()) ans=max(ans,t1.getans(min(mi1,mi2))-(*it).first+min(mi1,mi2)+x);
			if (it!=s1.begin())
			{
				ma2=(*(--it)).first;
				ans=max(ans,t1.getans(min(ma2-x,min(mi1,mi2)))-ma2+min(ma2-x,min(mi1,mi2))+x-t2.getans(ma2-x));
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
/*

k-x<mi1   >mi2



<mi1 
<mi2

t1.getans(P)+t2.getans(P)*/