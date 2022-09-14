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
const ll inf=1000000000000000001;
const int N=300010;
ll a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    ll sum=0ll;
    for (int i=1;i<=n;i++) sum+=a[i]-1;
    if (sum%2){
        cout<<"errorgorn\n";
    } else {
        cout<<"maomao90\n";
    }
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