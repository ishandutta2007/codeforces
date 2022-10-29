#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define id(l,r) (l+r|l!=r)
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back 
#define mp make_pair
using namespace std;
const int N=5e5+8;
int fa[N],sz[N],top;
pii stk[N];
int op[N],a[N],b[N],d,t[N],D[N];
vector<pii> g[N<<1];
void add(const int &l,const int &r,const int &L,const int &R,const pii &val){
	if(L<=l&&r<=R){
		g[id(l,r)].pb(val);
		return ;
	}
	int m=l+r>>1;
	if(L<=m)add(l,m,L,R,val);
	if(R>m)add(m+1,r,L,R,val);
}
int find(int x){
	if(fa[x]==x)return x;
	return find(fa[x]);
}
void solve(const int &l,const int &r){
	int now=top;
	for(auto w:g[id(l,r)]){
		int u=w.fi,v=w.se;
		u=find(u),v=find(v);
		if(u==v)continue;
		if(sz[u]<sz[v])swap(u,v);
		sz[u]+=sz[v];
	//	cout<<l<<' '<<r<<' '<<u<<' '<<v<<"??????\n";
		fa[v]=u;
		stk[++top]=mp(u,v);
	}
	if(l==r){
		if(op[l]==2){
			int u=find(a[l]);
			printf("%d\n",sz[u]);
		}
		while(top>now){
			int u=stk[top].fi,v=stk[top].se;
			sz[u]-=sz[v];
			fa[v]=v;
			--top;
		}
		return;
	}
	int m=l+r>>1;
	solve(l,m);
	solve(m+1,r);
	while(top>now){
		int u=stk[top].fi,v=stk[top].se;
		sz[u]-=sz[v];
		fa[v]=v;
		--top;
	}
}
int main(){
	int n,q,k;
	scanf("%d%d%d",&n,&q,&k);
	rep(i,1,q+1){
		scanf("%d",&op[i]);
		if(op[i]==1){
			scanf("%d%d",&a[i],&b[i]);
			t[i]=d;
		}
		else if(op[i]==2){
			scanf("%d",&a[i]);
			t[i]=d;
		}
		else{
			t[i]=++d;D[d]=i;
		}
	}
	rep(i,1,q+1){
		if(op[i]==1){
			if(t[i]+k>d){
			//	cout<<i<<' '<<q<<"comein\n";
				add(1,q,i,q,mp(a[i],b[i]));
			}
			else{
				add(1,q,i,D[t[i]+k],mp(a[i],b[i]));
			}
		}
	}
	rep(i,1,n+1)fa[i]=i,sz[i]=1;
	solve(1,q);
}