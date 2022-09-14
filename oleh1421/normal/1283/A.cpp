#pragma GCC Optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
const long long mod=998244353;
typedef long long ll;
using namespace std;
mt19937_64 rng(time(NULL));
void solve(){
    int h,m;cin>>h>>m;
    int res=h*60+m;
    cout<<1440-res<<endl;
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