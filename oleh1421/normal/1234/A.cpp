//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
//#define inf 10000000000000001ll
//#define fi first
//#define se second
typedef long long ll;
using namespace std;
void solve(){
    int n;cin>>n;
    ll sum=0ll;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        sum+=x*1ll;
    }
    cout<<(sum+n-1)/n<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}