#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1000010;
void solve(){
    ll l,r;cin>>l>>r;
    if (l*2<=r){
        cout<<l<<" "<<l*2<<endl;
    } else cout<<"-1 -1\n";
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tt;cin>>tt;
    while (tt--){
        solve();
    }


    return 0;
}