#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200100;
const ll inf=1000000000000000001;
ll a[N];
vector<int>g[N];
bool used[N];
int mt[N];
bool dfs(int v){
    if (used[v]) return false;
    used[v]=true;
    for (int to:g[v]){
        if (mt[to]==-1 || dfs(mt[to])){
            mt[to]=v;
            return true;
        }
    }
    return false;
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) g[i].clear();
    for (int i=1;i<=n;i++){
        while (a[i]){
            if (a[i]<=n) g[a[i]].push_back(i);
            a[i]/=2;
        }
    }
    for (int i=1;i<=n;i++){
        mt[i]=-1;
        used[i]=false;
    }
    int res=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) used[j]=false;
        res+=dfs(i);
    }
    if (res==n) cout<<"YES\n";
    else cout<<"NO\n";

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

10 3
-5 -4 -3 -2 -1 0 1 2 3 4
1 0 4 1
1 5 9 1
2 0 9 3
**/