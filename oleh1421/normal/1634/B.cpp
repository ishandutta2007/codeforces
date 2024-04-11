#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
const int N=5000010;
const ll mod=998244353;

void solve(){
    ll n,x,y;cin>>n>>x>>y;
    for (int i=1;i<=n;i++){
        ll a;cin>>a;
        x^=a;
    }
    if (x%2==y%2) cout<<"Alice\n";
    else cout<<"Bob\n";

}
int32_t  main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

/**

**/