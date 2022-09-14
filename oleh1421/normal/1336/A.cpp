//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=300010;
vector<int>g[N];
int d[N];
int sz[N];
int a[N];
void dfs(int v,int pr,int cur){
    d[v]=cur;
    sz[v]=1;
    for (auto to:g[v]){
        if (to!=pr){
            dfs(to,v,cur+1);
            sz[v]+=sz[to];
        }
    }
    a[v]=d[v]-sz[v]+1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k;cin>>n>>k;
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0,0);
    sort(a+1,a+n+1);
    ll sum=0ll;
    for (int i=n;i>=n-k+1;i--){
        sum+=a[i];
    }
    cout<<sum;
    return 0;
}

/*
2 2
0 1
10 1
*/