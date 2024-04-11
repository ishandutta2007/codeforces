//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
#define double long double
const int N=500010;
vector<int>g[N];
int used[N];
int take[N];
void dfs(int v){
    used[v]=true;
    take[v]=1;
    for (int to:g[v]){
        if (used[to]){
            if (take[to]) take[v]=0;
        }
    }
    for (int to:g[v]){
        if (!used[to]){
            dfs(to);
        }
    }
}

void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) g[i].clear(),take[i]=0;
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i=1;i<=n;i++) used[i]=0;
    used[1]=1;
    dfs(1);
    for (int i=1;i<=n;i++){
        if (!used[i]){
            cout<<"NO\n";
            return;
        }
    }
    vector<int>ans;
    for (int i=1;i<=n;i++){
        if (take[i]) ans.push_back(i);
    }
    cout<<"YES\n";
    cout<<ans.size()<<endl;
    for (int i:ans) cout<<i<<" ";
    cout<<endl;
//    for (int i=1;i<=n;i++) used[i]=0;
//    used[1]=1;
//    dfs1(1);
//    for (int i=1;i<=n;i++){
//        if (!used[i]){
//            cout<<"NO\n";
//            return;
//        }
//        used1[i]=0;
//    }
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
/*

*/