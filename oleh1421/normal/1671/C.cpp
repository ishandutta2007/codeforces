#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
typedef long double ld;
//#define int ll
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
const ll mod=998244353;
const int N=300010;
ll a[N];
ll d[N];
void solve(){
    ll n,x;cin>>n>>x;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll sum=0ll;
    for (int i=1;i<=n;i++) sum+=a[i];
    d[n+1]=-1ll;
    for (int i=n;i>=1;i--){
        if (sum>x) d[i]=-1;
        else d[i]=(x-sum)/(1ll*i);
        sum-=a[i];
    }
    ll res=0ll;
    for (int i=1;i<=n;i++){
        res+=(d[i]-d[i+1])*i;
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
  ,        .
**/