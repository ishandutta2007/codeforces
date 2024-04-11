/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
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
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//

using pll = pair<ll,ll>;
ll n,m,mx = 100000000000000,d[100010],vis[100010] = {0};
pll dat[400010],t[2][400010];
vector<int> v,G[100010];
 
pll cal(pll p, pll q,int i){
	if(i==0){
		if(p.first<q.first) return p;
		else return q;
	}
	if(i==1){
		if(p.first<q.first) return q;
		else return p;
	}
}
 
void build(){
	for(int i=m-1;i>0;i--) dat[i] = cal(dat[i<<1],dat[i<<1|1],0);
}
 
pll query(int l, int r){
	pll mn = {mx,0};
	for(l += m, r += m; l<r; l >>= 1,r >>= 1){
		if(l&1) mn = cal(mn,dat[l++],0);
		if(r&1) mn = cal(mn,dat[--r],0);
	}
	return mn;
}
 
void build2(){
	for(int i=n-1;i>0;i--){
		t[0][i] = cal(t[0][i<<1],t[0][i<<1|1],0);
		t[1][i] = cal(t[1][i<<1],t[1][i<<1|1],1);
	}
}
 
pll query2(int l, int r,int x){
	pll mn = {mx,0},mx = {-1,0};
	for(l += n, r += n; l<r; l >>= 1, r >>= 1){
		if(l&1){
			if(x==0) mn = cal(mn,t[0][l++],0);
			else mx = cal(mx,t[1][l++],1);
		}
		if(r&1){
			if(x==0) mn = cal(mn,t[0][--r],0);
			else mx = cal(mx,t[1][--r],1);
		}
	}
	if(x==0) return mn;
	else return mx;
}
 
pll lca(int l,int r){
    if(l==r){
        return {d[l],l};
    }
    return query(min(vis[l],vis[r]),max(vis[l],vis[r]));
}
 
pll range_lca(int l, int r){
    r++;
    pll p = query2(l,r,0),q = query2(l,r,1);
    ll  mn = p.second,mx = q.second;
    return lca(mn,mx);
}
 
pll sp_lca(int l, int r,int x){
    if(l==x) return range_lca(l+1,r);
    if(x==r) return range_lca(l,r-1);
    pll p = range_lca(l,x-1), q = range_lca(x+1,r);
    int v1 = p.second, v2 = q.second;
    return lca(v1,v2);
}
 
void dfs(int s){
	v.push_back(s);
	for(int x:G[s]){
		if(d[x]!=-1) continue;
		d[x] = d[s] + 1;
		dfs(x);
		v.push_back(s);
	}
}
 
int main(){
    fio;
	int i,q;
	cin >> n >> q;
	for(i=1;i<n;i++){
		int a; cin >> a; a--;
		G[a].push_back(i); G[i].push_back(a);
	}
	for(i=0;i<n;i++) d[i] = -1;
	d[0] = 0; dfs(0);
	m = v.size();
	for(i=0;i<m;i++){
        dat[i+m] = {d[v[i]],v[i]};
		if(!vis[v[i]] && v[i]) vis[v[i]] = i;
	}
	for(i=0;i<n;i++){
		t[0][i+n] = {vis[i],i};
		t[1][i+n] = {vis[i],i};
	}
	build(); build2();
	for(i=0;i<q;i++){
		int x,y;
		cin >> x >> y;
		x--;
		pll mn = query2(x,y,0), mx = query2(x,y,1);
		ll l = mn.second, r = mx.second;
        y--;
        pll p = sp_lca(x,y,l), q = sp_lca(x,y,r);
        if(p.first>=q.first) cout << l + 1 << " " << p.first <<endl;
        else cout << r + 1 << " " << q.first << endl;
	}
}