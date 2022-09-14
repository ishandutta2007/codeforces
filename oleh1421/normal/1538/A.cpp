#include <bits/stdc++.h>

typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=300010;
const ll mod=1000000007;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int mn=1,mx=1;
    for (int i=2;i<=n;++i){
        if (a[i]>a[mx]) mx=i;
        if (a[i]<a[mn]) mn=i;
    }
    if (mn>mx) swap(mn,mx);
    cout<<min({mn+n-mx+1,mx,n-mn+1})<<endl;

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