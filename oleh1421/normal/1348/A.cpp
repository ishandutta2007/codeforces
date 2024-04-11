#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
void solve(){
    int n;cin>>n;
    ll a=(1<<n);
    for (int i=1;i<n/2;i++) a+=(1<<i);
    ll b=0ll;
    for (int i=n/2;i<n;i++) b+=(1<<i);
    cout<<a-b<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
2 3
1 100
*/