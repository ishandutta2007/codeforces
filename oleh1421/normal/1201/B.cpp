#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
///#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
int a[1000001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    ll sum=0ll;
    for (int i=1;i<=n;i++) sum+=a[i]*1ll;
    ll maxx=0ll;
    for (int i=1;i<=n;i++) maxx=max(maxx,a[i]*1ll);
    if (sum%2 || maxx*2ll>sum) cout<<"NO";
    else cout<<"YES";
    return 0;
}