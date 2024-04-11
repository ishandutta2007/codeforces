#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=1000100;
const ll mod=998244353;
int v[N];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) {
        cin>>v[i];

    }
    for (int i=1;i<=k;i++){
        if (v[n-i+1]>0){
            cout<<0<<endl;
            return;
        }
        v[n-i+1]=0;
    }
    ll res=1ll;
    for (int i=1;i<=k;i++) res=(res*i)%mod;
    for (int i=1;i<=n-k;i++){
        if (v[i]==0){
//            0<=x[i+k]<=k;
            res*=(k+1ll);
            res%=mod;
        } else if (v[i]>0){
//            x[i+k]=v[i]+k


        } else {
//            0<=x[i]<=i+k-1
            res*=(i+k);
            res%=mod;
        }

    }
    cout<<res<<endl;



}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

/**
1
5 2
-1 1 2 0 0


4 11

3 6
2 3
1 1

2 3
999999999 1000000000
**/