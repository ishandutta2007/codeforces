#pragma GCC optimize("Ofast")
//#pragma GCC optimization("unroll-loops")
//#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N=100010;
const int K=510;
const ll mod=998244353;
vector<pair<int,int> >g[N];
int ans[N];
void dfs(int v,int pr,int val){
    for (auto cur:g[v]){
        if (cur.first!=pr){
            ans[cur.second]=val;
            dfs(cur.first,v,5-val);
        }
    }
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) g[i].clear();
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back({b,i});
        g[b].push_back({a,i});
    }
    for (int i=1;i<=n;i++){
        if (g[i].size()>2){
            cout<<-1<<endl;
            return;
        }
    }
    for (int i=1;i<=n;i++){
        if (g[i].size()==1){
            dfs(i,0,2);
            break;
        }
    }
    for (int i=1;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;

}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}
/**
ababababa
2
1 5 c
2 1 7 aba
**/