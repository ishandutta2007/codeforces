//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=44;

void solve(){
    int w,h,n;cin>>w>>h>>n;
    int mult=1;
    while (w%2==0){
        mult*=2;
        w/=2;
    }
    while (h%2==0){
        mult*=2;
        h/=2;
    }
    if (mult>=n) cout<<"YES\n";
    else cout<<"NO\n";

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
/*

3 0
aa
bcd
*/