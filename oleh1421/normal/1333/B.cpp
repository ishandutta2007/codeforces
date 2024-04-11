#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=300010;
int a[N];
int b[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    reverse(a+1,a+n+1);
    reverse(b+1,b+n+1);
    if (a[n]!=b[n]){
        cout<<"NO\n";
        return;
    }
    bool ok1=false;
    bool ok2=false;
    if (a[n]==-1) ok1=true;
    else if (a[n]==1) ok2=true;
    for (int i=n-1;i>=1;i--){
        if (a[i]<b[i] && !ok2){
            cout<<"NO\n";
            return;
        }
        if (a[i]>b[i] && !ok1){
            cout<<"NO\n";
            return;
        }
        if (a[i]==-1) ok1=true;
        else if (a[i]==1) ok2=true;
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