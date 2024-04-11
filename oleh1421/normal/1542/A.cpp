#include <bits/stdc++.h>

typedef long long ll;
//#define endl '\n'
using namespace std;
//#define int ll
const int N=300010;

void solve(){
    int n;cin>>n;
    int ans=0;
    for (int i=1;i<=n*2;i++){
        int x;cin>>x;
        if (x%2) ans++;
        else ans--;
    }
    if (ans) cout<<"No\n";
    else cout<<"Yes\n";
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
//(f[n]/f[l])*dp[>0][2]