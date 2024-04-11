//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//const ll mod=1000000007ll;
using namespace std;
#define endl '\n'
const int N=200010;
const int Lg=20;
void solve(){
    int n;cin>>n;
    if (n%2) cout<<7;
    else cout<<1;
    for (int i=1;i<=(n-2)/2;i++) cout<<1;
    cout<<endl;
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