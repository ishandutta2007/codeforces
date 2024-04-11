#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define fi first
#define se second
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;
const int N=(int)2e5+9;
int pp[N],pos1[N],pos2[N],in;
ll e[N];
vector<pii> g[N];
struct node{
	ll a,b,c,ab,bc,abc,lazy;
}; 
node seg[N<<2];
void pushup(int pos){
	seg[pos].a=max(seg[pos<<1].a,seg[pos<<1|1].a);
	seg[pos].b=min(seg[pos<<1].b,seg[pos<<1|1].b);
	seg[pos].c=max(seg[pos<<1].c,seg[pos<<1|1].c);
	seg[pos].ab=max(max(seg[pos<<1].ab,seg[pos<<1|1].ab),seg[pos<<1].a-2*seg[pos<<1|1].b);
	seg[pos].bc=max(max(seg[pos<<1].bc,seg[pos<<1|1].bc),-2*seg[pos<<1].b+seg[pos<<1|1].c);
	seg[pos].abc=max(max(seg[pos<<1].abc,seg[pos<<1|1].abc),max(seg[pos<<1].a+seg[pos<<1|1].bc,seg[pos<<1].ab+seg[pos<<1|1].c));
}
void build(int pos,int l,int r,int L,int R,ll val){
	if(L<=l&&r<=R){
		seg[pos].a+=val;
		seg[pos].b+=val;
		seg[pos].c+=val;
		seg[pos].ab-=val;
		seg[pos].bc-=val;
		seg[pos].lazy+=val;
		return;
	}
	int mid=(l+r)>>1;
	if(seg[pos].lazy){
		build(pos<<1,l,mid,l,mid,seg[pos].lazy);
		build(pos<<1|1,mid+1,r,mid+1,r,seg[pos].lazy);
		seg[pos].lazy=0;
	}
	if(L<=mid)build(pos<<1,l,mid,L,R,val);
	if(R>mid)build(pos<<1|1,mid+1,r,L,R,val);
	pushup(pos);
}
void dfs(int u,int f){
	for(auto w:g[u]){
		int v=w.fi,id=w.se;
		if(v==f)continue;
		pp[id]=v;
		pos1[v]=++in;
		dfs(v,u);
		pos2[v]=++in;
	}
}
int main()
{
	int n,q;
	ll w,last=0;
	scanf("%d%d%lld",&n,&q,&w);
	rep(i,1,n){
		int u,v;
		scanf("%d%d%lld",&u,&v,&e[i]);
		g[u].pb({v,i});
		g[v].pb({u,i});
	}
	dfs(1,0);
	rep(i,1,n){
		int id=pp[i];
		build(1,1,in,pos1[id],pos2[id]-1,e[i]);
	}
//	cout<<seg[1].abc<<"???\n";
	while(q--){
		int d_,dd;
		ll e_,ee;
		scanf("%d%lld",&d_,&e_);
		dd=(d_+last)%(n-1)+1;
		ee=(e_+last)%w;
		int id=pp[dd];
		build(1,1,in,pos1[id],pos2[id]-1,ee-e[dd]);
		e[dd]=ee;
		last=seg[1].abc;
		printf("%lld\n",last);
	}
}