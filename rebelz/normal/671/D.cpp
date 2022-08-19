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
	ll mina,lazy;
}t[1100000];

const ll inf=1ll<<50;
int n,m,mcnt;
int lf[300005],rg[300005],ss[300005],tt[300005],val[300005],id[300005];
vector<int> be[300005],ed[300005],v[300005];
ll ans[300005];

void build(int id,int l,int r){
	t[id].mina=inf;
	if(l==r) return;
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
}

void chk(ll &x){if(x>inf)x=inf;}

void pushdown(int id){
	if(t[id].lazy){
		t[id<<1].lazy+=t[id].lazy,t[id<<1|1].lazy+=t[id].lazy;
		t[id<<1].mina+=t[id].lazy,t[id<<1|1].mina+=t[id].lazy;
		chk(t[id<<1].mina),chk(t[id<<1|1].mina);
		chk(t[id<<1].lazy),chk(t[id<<1|1].lazy);
		t[id].lazy=0;
	}
}

void update(int id,int l,int r,int x,ll c){
	if(l==r) return (void)(t[id].mina=c);
	pushdown(id);
	int mid=(l+r)/2;
	if(x<=mid) update(id<<1,l,mid,x,c);
	else update(id<<1|1,mid+1,r,x,c);
	t[id].mina=min(t[id<<1].mina,t[id<<1|1].mina);
	chk(t[id].mina);
}

void change(int id,int l,int r,int ql,int qr,ll c){
	if(ql>qr) return;
	if(l==ql&&r==qr){
		t[id].lazy+=c,t[id].mina+=c;
		chk(t[id].lazy),chk(t[id].mina);
		return;
	}
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
	else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
	t[id].mina=min(t[id<<1].mina,t[id<<1|1].mina);
	chk(t[id].mina);
}

ll query(int id,int l,int r,int ql,int qr){
	if(ql>qr) return inf;
	if(l==ql&&r==qr) return t[id].mina;
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
	else return min(query(id<<1,l,mid,ql,mid),query(id<<1|1,mid+1,r,mid+1,qr));
}

void dfs1(int u,int fa){
	lf[u]=mcnt+1;
	for(auto x:be[u]) id[x]=++mcnt;
	for(auto x:v[u]){
		if(x==fa) continue;
		dfs1(x,u);
	}
	rg[u]=mcnt;
}

void dfs2(int u,int fa){
	ll sum=0;
	for(auto x:v[u]){
		if(x==fa) continue;
		dfs2(x,u);
		sum+=ans[x];
		sum=min(sum,3*inf);
	}
	if(u==1) return (void)(ans[1]=sum);
	for(auto x:be[u]) update(1,1,m,id[x],sum+val[x]);
	for(auto x:ed[u]) update(1,1,m,id[x],inf);
	for(auto x:v[u]) if(x!=fa) change(1,1,m,lf[x],rg[x],sum-ans[x]);
	ans[u]=query(1,1,m,lf[u],rg[u]);
}

int main(){
	n=readint(); m=readint();
	int x,y;
	for(int i=1;i<=n-1;i++){
		x=readint(); y=readint();
		v[x].push_back(y); v[y].push_back(x);
	}
	for(int i=1;i<=m;i++){
		ss[i]=readint(); tt[i]=readint(); val[i]=readint();
		be[ss[i]].push_back(i); ed[tt[i]].push_back(i);
	}
	build(1,1,m);
	dfs1(1,-1);
	dfs2(1,-1);
	printf("%lld\n",ans[1]>=inf?-1:ans[1]);
	return 0;
}