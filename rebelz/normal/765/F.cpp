#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int id,l,r;
}q[300005];

int n,m;
int ans[300005],a[100005],p[100005];
vector<pii> v[100005];

namespace sgt1{
	pii val[300000];
	void build(int id,int l,int r){
		val[id]=mp(-1,-1);
		if(l==r) return;
		int mid=(l+r)/2;
		build(id<<1,l,mid);
		build(id<<1|1,mid+1,r);
	}
	void change(int id,int l,int r,int p,pii c){
		if(l==r) return (void)(chkmax(val[id],c));
		int mid=(l+r)/2;
		if(p<=mid) change(id<<1,l,mid,p,c);
		else change(id<<1|1,mid+1,r,p,c);
		val[id]=max(val[id<<1],val[id<<1|1]);
	}
	pii query(int id,int l,int r,int ql,int qr){
		if(ql>qr) return mp(-1,-1);
		if(l==ql&&r==qr) return val[id];
		int mid=(l+r)/2;
		if(qr<=mid) return query(id<<1,l,mid,ql,qr);
		else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
		else return max(query(id<<1,l,mid,ql,mid),query(id<<1|1,mid+1,r,mid+1,qr));
	}
}

namespace sgt2{
	int val[300000];
	void build(int id,int l,int r){
		val[id]=1<<30;
		if(l==r) return;
		int mid=(l+r)/2;
		build(id<<1,l,mid);
		build(id<<1|1,mid+1,r);
	}
	void change(int id,int l,int r,int ql,int qr,int c){
		if(l==ql&&r==qr) return (void)(chkmin(val[id],c));
		int mid=(l+r)/2;
		if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
		else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
		else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
	}
	int query(int id,int l,int r,int p){
		if(l==r) return val[id];
		int mid=(l+r)/2;
		if(p<=mid) return min(val[id],query(id<<1,l,mid,p));
		else return min(val[id],query(id<<1|1,mid+1,r,p));
	}
}

void work(bool t){
	sgt1::build(1,1,n);
	sgt2::build(1,1,n);
	if(!t){
		for(int i=1;i<=m;i++) v[q[i].r].push_back(mp(q[i].l,q[i].id));
	}
	else{
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<=m;i++) v[n-q[i].l+1].push_back(mp(n-q[i].r+1,q[i].id));
	}
	for(int i=1;i<=n;i++){	
		int now=1e9,tmp=i;
		while(now>=p[a[i]]){
			int pl=upper_bound(p+1,p+n+1,now)-p-1;
			pii nxt=sgt1::query(1,1,n,a[i],pl);
			if(nxt.fi==-1) break;
			sgt2::change(1,1,n,1,nxt.fi,nxt.se-p[a[i]]);
			if(nxt.se==p[a[i]]) break;
			now=(p[a[i]]+nxt.se)/2;
		}
		sgt1::change(1,1,n,a[i],mp(i,p[a[i]]));
		for(auto x:v[i]) chkmin(ans[x.se],sgt2::query(1,1,n,x.fi));
	}
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) p[i]=a[i]=readint();
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++) a[i]=lower_bound(p+1,p+n+1,a[i])-p;
	m=readint();
	for(int i=1;i<=m;i++) q[i].l=readint(),q[i].r=readint(),q[i].id=i;
	memset(ans,0x3f,sizeof(ans));
	work(0);
	reverse(a+1,a+n+1);
	work(1);
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}