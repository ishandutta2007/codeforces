//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
#define endl '\n'
using namespace std;
const int N=100010;
void solve(){
    int n,k1,k2;cin>>n>>k1>>k2;
    int w=min(k1,k2)+abs(k1-k2)/2;
    int b=min(n-k1,n-k2)+abs(k1-k2)/2;
    int x,y;cin>>x>>y;
    if (x<=w && y<=b) cout<<"YES\n";
    else cout<<"NO\n";
}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}