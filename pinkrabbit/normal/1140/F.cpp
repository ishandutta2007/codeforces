#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define LL long long
#define MN 600005
#define MS 1048576
#define MK 10000005
int q;
map<int,int>mp[MN];
struct edg{
	int u,v;
	edg(){}
	edg(int u,int v):u(u),v(v){}
};
vector<edg>G[MS];
void Add(int i,int l,int r,int a,int b,edg x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){G[i].push_back(x);return;}
	Add(i<<1,l,(l+r)>>1,a,b,x),Add(i<<1|1,((l+r)>>1)+1,r,a,b,x);
}
LL Ans[MN];int fa[MN],sz[MN],lb[MN],rb[MN];
int ff(int x){return fa[x]?ff(fa[x]):x;}
int stk[MN],tp;LL ans;
void DFS(int i,int l,int r){
	int ot=tp;
	for(auto x:G[i]){
		int u=ff(x.u),v=ff(3e5+x.v);
		if(u==v)continue;
		if(sz[u]<sz[v])swap(u,v);
		ans+=(LL)lb[u]*rb[v]+(LL)rb[u]*lb[v];
		fa[v]=u,lb[u]+=lb[v],rb[u]+=rb[v],sz[u]+=sz[v];
		stk[++tp]=v;
	}
	if(l==r)Ans[l]=ans;
	else DFS(i<<1,l,(l+r)>>1),DFS(i<<1|1,((l+r)>>1)+1,r);
	while(tp!=ot){
		int u=stk[tp--],v=fa[u];
		lb[v]-=lb[u],rb[v]-=rb[u],sz[v]-=sz[u];
		fa[u]=0;
		ans-=(LL)lb[u]*rb[v]+(LL)rb[u]*lb[v];
	}
}
int main(){
	scanf("%d",&q);
	F(i,1,6e5)(i<=3e5?lb:rb)[i]=sz[i]=1;
	F(i,1,q){
		int u,v;
		scanf("%d%d",&u,&v);
		if(mp[u][v])Add(1,1,q,mp[u][v],i-1,edg(u,v)),mp[u][v]=0;
		else mp[u][v]=i;
	}
	F(i,1,3e5)for(auto x:mp[i])if(x.second)Add(1,1,q,x.second,q,edg(i,x.first));
	DFS(1,1,q);
	F(i,1,q)printf("%lld ",Ans[i]);
	return 0;
}

// lg