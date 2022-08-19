#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	mutable int l,r; ll lst;
	node(int l1=0,int r1=0,ll lst1=0):l(l1),r(r1),lst(lst1){}
	bool operator<(const node c)const{return l<c.l;}
};

struct item{
	ll mx,r,id,val;
	bool operator<(const item c)const{return val<c.val;}
}a[100005];

int n,m; ll ans=0;
ll st[100005],p[100005],k[100005];
set<node> s;

set<node>::iterator split(int x){
	auto it=s.lower_bound(node(x,0,0));
	if(it!=s.end()&&it->l==x) return it;
	it--;
	int l=it->l,r=it->r,v=it->lst;
	s.erase(it);
	s.insert(node(l,x-1,v));
	return s.insert(node(x,r,v)).fi;
}

namespace pt{
	struct tree{
		int lch,rch;
		ll sumv,sumr;
	}t[6000005];
	int tot;
	int vs[100005];
	void build(int id,int l,int r){
		if(l==r) return;
		int mid=(l+r)/2;
		build(t[id].lch=++tot,l,mid);
		build(t[id].rch=++tot,mid+1,r);
	}
	int change(int id,int l,int r,int x,ll c1,ll c2){
		int rt=++tot;
		t[rt]=t[id],t[rt].sumv+=c1,t[rt].sumr+=c2;
		if(l==r) return rt;
		int mid=(l+r)/2;
		if(x<=mid) t[rt].lch=change(t[rt].lch,l,mid,x,c1,c2);
		else t[rt].rch=change(t[rt].rch,mid+1,r,x,c1,c2);
		return rt;
	}
	ll query(int id1,int id2,int l,int r,int x,ll c){
		if(l==r) return t[id2].sumv-t[id1].sumv;
		int mid=(l+r)/2;
		if(x<=mid) return query(t[id1].lch,t[id2].lch,l,mid,x,c)+(t[t[id2].rch].sumr-t[t[id1].rch].sumr)*c;
		else return query(t[id1].rch,t[id2].rch,mid+1,r,x,c)+t[t[id2].lch].sumv-t[t[id1].lch].sumv;
	}
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++){
		st[i]=readint(); a[i].mx=readint(); a[i].r=readint(); a[i].id=i;
		s.insert(node(i,i,0));
		a[i].val=a[i].r==0?1<<30:a[i].mx/a[i].r+1;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) p[a[i].id]=i;
	for(int i=1;i<=n;i++) k[i]=a[i].val;
	pt::build(pt::vs[0]=0,1,n);
	for(int i=1;i<=n;i++) pt::vs[i]=pt::change(pt::vs[i-1],1,n,p[i],a[p[i]].mx,a[p[i]].r);
	m=readint();
	int t,x,y,tmp;
	for(int i=1;i<=m;i++){
		t=readint(); x=readint(); y=readint();
		auto it2=split(y+1),it1=split(x);
		ans=0;
		for(auto it=it1;it!=it2;it++){
			if(it->lst==0) ans+=min(a[p[it->l]].mx,st[it->l]+a[p[it->l]].r*t);
			else{
				tmp=upper_bound(k+1,k+n+1,t-it->lst)-k-1;
				if(tmp==0) ans+=(pt::t[pt::vs[it->r]].sumr-pt::t[pt::vs[it->l-1]].sumr)*(t-it->lst);
				else ans+=pt::query(pt::vs[it->l-1],pt::vs[it->r],1,n,tmp,t-it->lst);
			}
		}
		s.erase(it1,it2);
		s.insert(node(x,y,t));
		printf("%lld\n",ans);
	}
	return 0;
}