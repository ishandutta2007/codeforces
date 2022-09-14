//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse,avx,avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
mt19937_64 rnd(time(NULL));
const int N=500100;
const ll mod=1000000007;
ll a[N];
void solve(int Case){
    ll n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (k<=n){
        ll sum=0ll;
        for (int i=1;i<=k;i++) sum+=a[i];
        ll res=sum;
        for (int i=k+1;i<=n;i++) {
            sum+=a[i]-a[i-k];
            res=max(res,sum);
        }
        cout<<res+k*(k-1)/2ll<<endl;
        return;
    }
    ll res=0ll;
    for (int i=1;i<=n;i++) res+=a[i];
    res+=k*n;
    res-=n*(n+1ll)/2ll;
    cout<<res<<endl;


}
int32_t main() {
//    freopen("seabattle.in","r",stdin);
//    freopen("seabattle.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt=1;
    cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}
/**
1
3
1 -1 1
**/