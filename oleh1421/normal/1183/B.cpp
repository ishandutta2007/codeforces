#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
void solve(){
    int n,k;cin>>n>>k;
    int minx=100000001;
    int maxx=0;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        maxx=max(maxx,x);
        minx=min(minx,x);
    }
    if (minx+k>=maxx-k) cout<<minx+k<<endl;
    else cout<<-1<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--) solve();
    return 0;
}