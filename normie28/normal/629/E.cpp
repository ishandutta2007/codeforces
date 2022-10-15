
// Problem : E. Famil Door and Roads
// Contest : Codeforces - Codeforces Round #343 (Div. 2)
// URL : https://codeforces.com/problemset/problem/629/E
// Memory Limit : 512 MB
// Time Limit : 5000 ms
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
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
//---------END-------//
 
#define pb push_back
 
const int MN = 1e5+5, LG = 20;
int sp[MN][LG], dep[MN], sz[MN], N, M, i, x, y, w;
vi adj[MN]; ll d[MN], u[MN];
 
void dfs(int n,int p,int dd){
    dep[n]=dd; sp[n][0]=p; sz[n] = 1;
    for(auto v : adj[n]){
        if(v==p) continue;
        dfs(v, n, dd+1); sz[n] += sz[v];
        d[n] += d[v]+sz[v];
    }
}
 
void dfs2(int n,int p,ll w){
    u[n] = w;
    for(auto v : adj[n]){
        if(v==p) continue;
        dfs2(v,n,w+d[n]-d[v]+N-2*sz[v]);
    }
}
 
int lca(int x,int y){
    w=0;
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=LG-1;i>=0;i--){
        if((1<<i)<=dep[x]-dep[y])
            x = sp[x][i], w += (1<<i);
    }
    if(x==y) return x;
    for(int i=LG-1;i>=0;i--){
        if(sp[x][i]!=sp[y][i]){
            x = sp[x][i];
            y = sp[y][i];
            w += (1<<(i+1));
        }
    }
    w += 2;
    return sp[x][0];
}
 
int adv(int x,int s){
    for(int i=LG-1;i>=0;i--){
        if((1<<i)<=s){
            s -= (1<<i);
            x = sp[x][i];
        }
    }
    return x;
}
 
int main(){
	fio;
	cin>>N>>M;
    for(i=1;i<N;i++){
    	cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1,0,1); dfs2(1,0,0);
    for(int j=1;j<LG;j++){
        for(i=1;i<=N;i++)
            sp[i][j]=sp[sp[i][j-1]][j-1];
    }
    for(i=1;i<=M;i++){
    	cin>>x>>y;
        int l = lca(x,y);
        if(l==x||l==y){
            if(dep[x]>dep[y]) swap(x,y);
            int heh = adv(y,dep[y]-dep[x]-1);
            long double a = (u[heh]-(N-sz[heh]))/(long double)(N-sz[heh]);
            long double b = d[y]/(long double)sz[y];
            cout << fixed << setprecision(9) << a+b+w+1 << "\n";
        }
        else{
            long double a = d[x]/(long double)sz[x];
            long double b = d[y]/(long double)sz[y];
            cout << fixed << setprecision(9) << a+b+w+1 << "\n";
        }
    }
}