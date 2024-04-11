
// Problem : E. Blood Cousins Return
// Contest : Codeforces - Codeforces Round #151 (Div. 2)
// URL : https://codeforces.com/problemset/problem/246/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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
//---------END-------//
const int N = 1e5 + 5, mod = 1e9 + 7;
string name[N];
vector<int> adj[N];
map<int, set<string> > *mp[N];
vector<pair<int, int>> query[N];
int sz[N], res[N];
 
void dfs(int node, int level){
    int mx = -1, mx_node;
    sz[node] = 1;
    for(auto i: adj[node]){
        dfs(i, level + 1);
        sz[node] += sz[i];
        if(sz[i] > mx){
            mx = sz[i];
            mx_node = i;
        }
    }
    if(mx == -1) mp[node] = new map<int, set<string> > ();
    else mp[node] = mp[mx_node];
    (*mp[node])[level].insert(name[node]);
    for(auto i: adj[node]){
        if(i == mx_node) continue;
        for(auto j: *mp[i]){
            for(auto k: j.second){
                (*mp[node])[j.first].insert(k);
            }
        }
        (*mp[i]).clear();
    }
    for(auto i: query[node]){
        res[i.second] = (*mp[node])[level + i.first].size();
    }
 
}
 
 
int main(){
	fio;
    int n, par, start;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> name[i] >> par;
        adj[par].push_back(i);
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int u, k;
        cin >> u >> k;
        query[u].push_back({k, i});
    }
    dfs(0, 1);
    for(int i = 0; i < m; i++){
        cout << res[i] << '\n';
    }
}