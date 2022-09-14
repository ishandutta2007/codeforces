//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=5010;
const ll mod=1000000007;

void solve(){
    string s;cin>>s;
    if (s[0]==')' || s.back()=='(' || s.size()%2) cout<<"NO\n";
    else cout<<"YES\n";
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