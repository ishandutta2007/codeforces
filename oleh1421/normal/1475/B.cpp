//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=300050;
mt19937 rnd(time(NULL));
const ll mod=1000000007;
void solve(){
    int n;cin>>n;
    if (n/2020 >= n%2020) cout<<"YES\n";
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