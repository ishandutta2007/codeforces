//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#define y2 y_2
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
//#define int ll
typedef long long ll;
typedef long double ld;
const ll inf=2e18;
const ll mod=1000000007;
const ll mod1=mod*mod;
const int N=2000100;
int a[N];
void solve(){
    int n,x;cin>>n>>x;
    for (int i=1;i<=n;i++) cin>>a[i];
    int mn=a[1],mx=a[1];
    int res=0;
    for (int i=2;i<=n;i++){
        mn=min(mn,a[i]);
        mx=max(mx,a[i]);
        if (mx-mn>2*x){
            res++;
            mn=a[i];
            mx=a[i];
        }
    }
    cout<<res<<'\n';

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}
//CRES
/**
2 3
1 2
2 1
0 0

**/