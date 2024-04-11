//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
///use char if you want a naive algorithm to pass
#include <bits/stdc++.h>
//#include <vector>
#define endl '\n'
typedef long long ll;
using namespace std;
ll a[300001];
void solve(){
    int n;cin>>n;
    ll sum=0ll;
    ll maxx=0ll;
    ll cur=0ll;
    for (int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
    for (int i=1;i<n;i++){
        cur+=a[i];
        cur=max(cur,0ll);
        maxx=max(maxx,cur);

    }
    cur=0ll;
    for (int i=2;i<=n;i++){
        cur+=a[i];
        cur=max(cur,0ll);
        maxx=max(maxx,cur);
    }
    if (sum>maxx) cout<<"YES\n";
    else cout<<"NO\n";
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    /*int cnt=0;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        cnt+=(c=='L');
    }*/

    return 0;
}