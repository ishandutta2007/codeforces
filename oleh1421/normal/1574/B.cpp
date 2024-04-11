//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//#define int ll
#define endl '\n'
const int N=1000100;
const ll mod=998244353;
const ll inf=1000000000000000000;

void solve(){
    int a,b,c,m;cin>>a>>b>>c>>m;
    if (a>b) swap(a,b);
    if (b>c) swap(c,b);
    if (a>b) swap(a,b);
    int mx=a-1+b-1+c-1;
    int mn=max(0,c-1-a-b);
    if (m>mx || m<mn) cout<<"NO\n";
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
//1 3 3 4
//0 1 2 3