#include <bits/stdc++.h>
#define endl '\n'
//#define int ll
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
typedef long double ld;
const ll inf=1e18;
const int N=1010;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    ll res=0ll;
    for (int i=2;i<=n;i++){
        res+=(a[i]-1)/(a[1]*2-1);
    }
    cout<<res<<'\n';




}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}