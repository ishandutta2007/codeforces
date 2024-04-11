//#pragma GCC opitmize ("Ofast")
//#pragma GCC opitmize ("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=510;
char a[8][8];
void solve(){
    ll n,k;cin>>n>>k;
    if (n>=k*k && (n+k)%2==0) cout<<"YES\n";
    else cout<<"NO\n";
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


/*
1
8889
3
333 998 1
*/