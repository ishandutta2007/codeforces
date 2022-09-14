#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=255;
const ll mod=1000000007;
const ll inf=1e18;
void solve(){
    int n;cin>>n;
    ll sum=0ll;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        sum+=x-1;
    }
    if (sum>=0) cout<<sum<<endl;
    else cout<<1<<endl;
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