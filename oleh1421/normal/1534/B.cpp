#include <bits/stdc++.h>

typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=500010;
const ll mod=1000000007;
ll a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    a[0]=a[n+1]=0;
    ll res=0ll;
    for (int i=1;i<=n;i++){
        if (a[i]>max(a[i-1],a[i+1])){
            res+=a[i]-max(a[i-1],a[i+1]);
            a[i]=max(a[i-1],a[i+1]);
        }
    }
    for (int i=1;i<=n+1;i++){
        res+=abs(a[i]-a[i-1]);
    }
    cout<<res<<endl;

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