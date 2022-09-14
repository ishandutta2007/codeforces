#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define int long long
using namespace std;
vector<int>g[200001];
vector<int>bigger[200001];
ll f(int i){
    return 1ll*(ll)bigger[i].size()*((ll)g[i].size()-(ll)bigger[i].size())*1ll;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        if (a>b) swap(a,b);
        bigger[a].push_back(b);
    }
    ll res=0ll;
    for (int i=1;i<=n;i++) {
        res+=f(i);
    }
    cout<<res<<endl;
    int tt;cin>>tt;
    while(tt--){
        int v;cin>>v;
        res-=f(v);
        for (auto to:bigger[v]){
            res-=f(to);
            bigger[to].push_back(v);
            res+=f(to);
        }
        bigger[v].clear();
        cout<<res<<endl;
    }
    return 0;
}