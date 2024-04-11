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
const int N=400000;
const ll mod=998244353ll;
vector<int>g[N];
int dp[N][2];
int mx=0;
void dfs(int v,int pr){
    if (g[v].size()==1){
        dp[v][0]=1;
        return;
    }
    bool L=false;
    for (auto to:g[v]){
        if (to==pr) continue;
        dfs(to,v);
        dp[v][0]|=dp[to][1];
        dp[v][1]|=dp[to][0];
        if (g[to].size()==1) L=true;
    }
    mx+=L;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int root=1;
    while (g[root].size()==1) root++;
    mx=n-1;
    for (int i=1;i<=n;i++){
        if (g[i].size()==1) mx--;
    }
    dfs(root,-1);
    int mn=1;
    for (int i=1;i<=n;i++){
        if (dp[i][0] && dp[i][1]) mn=3;
    }
    cout<<mn<<" "<<mx<<endl;
    return 0;
}