//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
#define endl '\n'
//#define int ll
const int N=1000100;
const ll mod=998244353;
const int Lg=61;
ll binpow(ll a,ll b){
    if (!b) return 1;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2);
}
ll a[N];
void solve(){
    int n,m,k;cin>>n>>m>>k;
    for (int i=1;i<=k;i++) cin>>a[i];
    sort(a+1,a+k+1);
    reverse(a+1,a+k+1);
    {

        ll sum=0ll;
        bool can=false;
        for (int i=1;i<=k;i++){
            if (a[i]>=2*m) sum+=a[i]/m;
            if (a[i]>=3*m) can=true;
        }
        if (sum>=n){
            if (n%2){
                if (can){
                    cout<<"Yes\n";
                    return;
                }
            } else {
                cout<<"Yes\n";
                return;
            }
        }

    }
    {

        ll sum=0ll;
        bool can=false;
        for (int i=1;i<=k;i++){
            if (a[i]>=2*n) sum+=a[i]/n;
            if (a[i]>=3*n) can=true;
        }
        if (sum>=m){
            if (m%2){
                if (can){
                    cout<<"Yes\n";
                    return;
                }
            } else {
                cout<<"Yes\n";
                return;
            }
        }

    }
    cout<<"No\n";

}


signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    cin>>tt;
    while(tt--){
        solve();
    }
    return 0;
}