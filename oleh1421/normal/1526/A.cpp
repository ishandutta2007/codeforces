#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=200010;
const int W=3010;
const double inf=1e18+5;
int a[N*2];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n*2;i++) cin>>a[i];
    sort(a+1,a+n*2+1);
    for (int i=1;i<=n;i++){
        cout<<a[i]<<" "<<a[i+n]<<" ";
    }
    cout<<endl;
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