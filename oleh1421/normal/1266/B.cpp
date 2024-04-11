#include <bits/stdc++.h>
typedef long long ll;
const long long mod=1000000007ll;
#define endl '\n'
using namespace std;
int cnt[10];
void solve(){
    ll x;cin>>x;
    if (x%14ll<=6 && x%14ll>0 && x>14ll) cout<<"YES\n";
    else cout<<"NO\n";

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}