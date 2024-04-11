#include <bits/stdc++.h>

typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=510;
const ll mod=1000000007;
void solve(){
    ll n,a,b;cin>>n>>a>>b;
    ll pw=1;
    while (pw<=n){
        if ((n-pw)%b==0){
            cout<<"Yes\n";
            return;
        }
        pw*=a;
        if (a==1) break;
    }
    cout<<"No\n";

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
//50 1000000007
//10000000000000000
//1970290678356000
//37435522888764000