#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=300055;
const ll mod=1000000007;
const ll inf=1e18;
int h[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>h[i];
    int mn=2;
    sort(h+1,h+n+1);
    for (int i=3;i<=n;i++){
        if (h[i]-h[i-1]<h[mn]-h[mn-1]){
            mn=i;
        }
    }
    for (int i=mn-1;i<=n;i++) {
        if (i==mn) continue;
        cout<<h[i]<<" ";
    }
    for (int i=1;i<mn-1;i++) cout<<h[i]<<" ";
    cout<<h[mn]<<endl;
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
/**
4
1 0 0 0
0 0 1 0
0 1 1 0
0 0 0 0
0 1
**/