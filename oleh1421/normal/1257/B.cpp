#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
//#define int long long
void solve(){
    int x,y;cin>>x>>y;
    if (x>=y){
        cout<<"YES\n";
        return;
    }
    if (x==1) {
        cout<<"NO\n";
    } else if (x<=3){
        if (y<=3) cout<<"YES\n";
        else cout<<"NO\n";
    } else cout<<"YES\n";
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