#include <bits/stdc++.h>

typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=510;
const ll mod=1000000007;
void solve(){
    ll n;cin>>n;
    ll Lcm=1ll;
    ll res=0ll;
    for (ll i=1;Lcm<=n;i++){
        ll nxt=(i+1)/__gcd(i+1,Lcm)*Lcm;
        res+=(n/Lcm-n/nxt)*(i+1ll);
        res%=mod;
        Lcm=nxt;
//        cout<<i<<" "<<Lcm<<endl;
    }
    cout<<res<<endl;
//    ll res1=0;
//    for (int i=1;i<=n;i++){
//        int j=1;
//        while (i%j==0) j++;
//        res1+=j;
//    }
//    cout<<res1<<endl;
//    6*2 + 4*3 + 1*4

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