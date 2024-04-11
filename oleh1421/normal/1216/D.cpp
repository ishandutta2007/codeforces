#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int long long
using namespace std;
int a[300001];

void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int z=a[2]-a[1];
    for (int i=2;i+1<=n;i++){
        z=__gcd(z,a[i+1]-a[i]);
    }
    ll y=0ll;
    for (int i=1;i<n;i++){
        ll cur=(a[n]-a[i])/z*1ll;
        y+=cur*1ll;
    }
    cout<<y<<" "<<z<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;tt=1;
    while (tt--){
        solve();
    }
    return 0;
}