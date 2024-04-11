#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//#define y2 y_2
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
//#define int ll
typedef long long ll;
typedef long double ld;
const int N=2000010;
vector<int>g[N];
int a[N];
set<int>st[N];
int w[N];
int ans=0;

void dfs(int v,int pr){
    st[v].insert(0);
    bool bad=false;
    for (int to:g[v]){
        if (to==pr) continue;
        dfs(to,v);
        if (st[to].size()>st[v].size()) {
            st[v].swap(st[to]);
            swap(w[v],w[to]);
        }
         for (int x:st[to]){
            if (st[v].find(x^w[to]^w[v]^a[v])!=st[v].end()) bad=true;
        }
        for (int x:st[to]){
            st[v].insert(x^w[v]^w[to]);
        }
    }
    w[v]^=a[v];
    if (bad){
        w[v]=0;
        st[v].clear();
        ans++;
    }
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    cout<<ans<<'\n';

}
int32_t main() {
//    freopen("5.034.in","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
//    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
4 3 2000
1 2 100
2 3 1000
2 4 1000
1.27
3,16,27,24,23,46
**/