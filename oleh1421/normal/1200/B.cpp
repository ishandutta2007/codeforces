#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
int h[111];
void solve(){
    int n,m,k;cin>>n>>m>>k;
    for (int i=1;i<=n;i++) cin>>h[i];
    for (int i=1;i<n;i++){
        int nxt=max(0,h[i+1]-k);
        if (h[i]+m<nxt){
            cout<<"NO\n";
            return;
        }
        m+=h[i]-nxt;
    }
    cout<<"YES\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}