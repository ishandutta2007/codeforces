#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=500010;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=2;i<=n;i++){
        if (a[i]>=a[i-1]){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}