#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=600010;
int p[N];
int c[N];
//const int K=3010;
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i]>>c[i];
    for (int i=1;i<=n;i++){
        if (p[i]<p[i-1] || c[i]<c[i-1] || p[i]-p[i-1]<c[i]-c[i-1]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}