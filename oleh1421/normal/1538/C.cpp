#include <bits/stdc++.h>

typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=300010;
const ll mod=1000000007;
int a[N];
void solve(){
    int n,l,r;cin>>n>>l>>r;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll res=0ll;
    for (int i=1;i<=n;i++){
        res+=upper_bound(a+1,a+n+1,r-a[i])-lower_bound(a+1,a+n+1,l-a[i]);
        if (a[i]*2>=l && a[i]*2<=r) res--;
    }
    cout<<res/2<<endl;


}
int32_t main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}