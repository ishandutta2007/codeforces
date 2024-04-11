//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=500010;
const ll mod=1000000007;
ll h[N];
ll pref[N];
ll pref1[N];
ll suf[N];
ll suf1[N];

void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>h[i];
    pref[1]=h[1];
    pref1[1]=h[1];
    for (int i=2;i<=n;i++){
        pref[i]=min(pref[i-1]+k-1,h[i]+k-1);
        pref1[i]=max(pref1[i-1]-k+1,h[i]);
        if (pref[i]<pref1[i]){
//            cout<<i<<" "<<pref[i]<<" "<<pref1[i]<<endl;
            cout<<"NO\n";
            return;
        }
    }
    if (pref[n]<h[n] || pref1[n]>h[n]){
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";

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