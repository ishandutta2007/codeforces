//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=1000010;
const ll mod=1000000007;
ll x[N];
ll cnt[65];
void solve(){
    int n;cin>>n;
    for (int i=0;i<60;i++) cnt[i]=0;
    for (int i=1;i<=n;i++) {
        cin>>x[i];
        for (int j=0;j<60;j++){
            if (x[i]&(1ll<<j)) cnt[j]++;
        }
    }
    ll res=0ll;
    for (int j=1;j<=n;j++){
        ll A=0ll,B=0ll;
        for (int a=0;a<60;a++){
            if (x[j]&(1ll<<a)){
                A+=((1ll<<a)%mod)*cnt[a];
                A%=mod;
                B+=((1ll<<a)%mod)*(n*1ll);
                B%=mod;
            } else {
                B+=((1ll<<a)%mod)*(cnt[a]*1ll);
                B%=mod;
            }
        }
        res+=A*B;
//        cout<<j<<" "<<res<<endl;
        res%=mod;
    }
    cout<<res<<endl;

}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
/*


*/