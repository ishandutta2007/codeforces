#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007ll;
#define endl '\n'
const int N=200010;
void solve(){
    int cnt=0;
    int n;cin>>n;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        cnt+=x%2;
    }
    if ((cnt==0 || cnt==n) && cnt%2==0) cout<<"NO\n";
    else cout<<"YES\n";
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}