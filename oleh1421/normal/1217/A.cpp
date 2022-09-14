#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
///#define int long long
typedef long long ll;
using namespace std;
void solve(){
    int a,b,c;cin>>a>>b>>c;
    if (a+c<=b){
        cout<<0<<endl;
        return;
    }
    cout<<min((a+c-b-1)/2,c)+1<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}