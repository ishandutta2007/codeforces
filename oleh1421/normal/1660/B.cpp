#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N=3000010;
const ll mod=998244353;
const ll inf=2000000000000000001;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if (a[n]<=a[n-1]+1){
        cout<<"YES\n";
        return;
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