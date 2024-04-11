//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
///use char if you want a naive algorithm to pass
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
const int N=200001;
string s[N];
string t[N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=0;i<n;i++) cin>>s[i];
    for (int i=0;i<m;i++) cin>>t[i];
    int q;cin>>q;
    while (q--){
        int x;cin>>x;
        x--;
        cout<<s[x%n]<<t[x%m]<<endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}