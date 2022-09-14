#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//#define y2 y_2
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
#define int ll
typedef long long ll;
typedef long double ld;
const int N=2000010;
ll a[N];
ll pref[N];
ll suf[N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=2;i<=n;i++){
        pref[i]=pref[i-1]+max(0ll,a[i-1]-a[i]);
    }
    for (int i=n-1;i>=1;i--){
        suf[i]=suf[i+1]+max(0ll,a[i+1]-a[i]);
    }
    for (int i=1;i<=m;i++){
        int s,t;cin>>s>>t;
        if (s<t){
            cout<<pref[t]-pref[s]<<'\n';
        } else {
            cout<<suf[t]-suf[s]<<'\n';
        }
    }



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