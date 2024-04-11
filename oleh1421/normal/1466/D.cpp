//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=400010;
const ll mod=1000000007;
ll w[N];
vector<int>g[N];
int cnt[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>w[i],g[i].clear();
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i=1;i<=n;i++) cnt[i]=g[i].size();
    vector<int>v;
    ll res=0ll;
    for (int i=1;i<=n;i++){
        res+=w[i];
        for (int j=2;j<=cnt[i];j++) v.push_back(w[i]);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    cout<<res<<" ";
    for (ll x:v){
        res+=x;
        cout<<res<<" ";
    }
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
/*


*/