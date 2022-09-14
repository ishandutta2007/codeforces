#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=2000010;
void solve(){
    ll a,b,c;cin>>a>>b>>c;
    if (a>b) swap(a,b);
    if (a*(c+1)>=b) cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}