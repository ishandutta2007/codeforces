#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=(1<<19);
const ll mod=1000000007;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int z=0;
    for (int i=1;i<=n;i++) z+=(a[i]<0);
    for (int i=1;i<=n;i++){
        if (i<=z) a[i]=-abs(a[i]);
        else a[i]=abs(a[i]);
    }
    if (is_sorted(a+1,a+n+1)) cout<<"YES\n";
    else cout<<"NO\n";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

/**
3 3
30 10 40
20 50 60
60 60 50

1001110110

1
5
1 2 4 2 1
4 2 2 1 1
  ,        .
**/