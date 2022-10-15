
// Problem : E. Little Girl and Problem on Trees
// Contest : Codeforces - Codeforces Round #169 (Div. 2)
// URL : https://codeforces.com/problemset/problem/276/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define piii pair<int,int>
#define piiii pair<int,piii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
int n;
int bit0[100010],bit1[100010];
int top[100010],ed[100010],id1[100010],idx;
int dep[100010],cnt[100010],par[100010],maxd;
vector<int> g[100010];
inline int lowbit(int _x){
	return _x&-_x;
}
inline void modify(int pos,int add,int* bit){
	for(int i=pos;i<=n;i+=lowbit(i))
		bit[i]+=add;
}
inline int query(int pos,int* bit){
	int res=0;
	for(int i=pos;i>0;i-=lowbit(i))
		res+=bit[i];
	return res;
}
inline void sectionAdd(int l,int r,int add,int* bit){
	modify(l,add,bit);
	modify(r+1,-add,bit);
}
inline void add_link_up(int v,int add,int d){
	if(dep[v]-d<dep[top[v]])
		sectionAdd(id1[top[v]],id1[v],add,bit1);
	else
		sectionAdd(id1[v]-d,id1[v],add,bit1);
}
inline void add_link_down(int v,int add,int d){
	if(dep[v]+d>dep[ed[top[v]]])
		sectionAdd(id1[v],id1[ed[top[v]]],add,bit1);
	else
		sectionAdd(id1[v],id1[v]+d,add,bit1);
}
inline void add_till_d(int add,int d){
	sectionAdd(1,cnt[d],add,bit0);
}
void dfs(int u,int fa,int tp){
	cnt[dep[u]]++;
	par[u]=fa;
	top[u]=tp;
	id1[u]=++idx;
	maxd=max(maxd,dep[u]);
	if(tp!=-1 && (ed[tp]==0 || dep[u]>dep[ed[tp]]))
		ed[tp]=u;
	for(int v:g[u]){
		if(v==fa) continue;
		dep[v]=dep[u]+1;
		if(fa==-1) dfs(v,u,v);
		else dfs(v,u,tp);
	}
}
int main(){
	int q,u,v;
	cin>>n>>q;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,-1,-1);
	for(int i=1;i<=maxd;i++)
		cnt[i]+=cnt[i-1];
	int opt,x,d;
	while(q--){
		cin>>opt>>v;
		if(opt==0){
			cin>>x>>d;
			if(v!=1){
				add_link_down(v,x,d);
				if(par[v]!=1 && d>0) add_link_up(par[v],x,d-1);
				d-=dep[v];
			}
			d=min(d,maxd);
			if(d>=0) add_till_d(x,d);
			if(v!=1 && d>0) add_link_down(top[v],-x,d-1);
		}else{
			cout<<query(cnt[dep[v]],bit0)+query(id1[v],bit1)<<endl;
		}
	}
}