#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void solve(){
    int a,b,c,n;cin>>a>>b>>c>>n;
    if ((a+b+c+n)%3){
        cout<<"NO\n";
        return;
    }
    int x=(a+b+c+n)/3;
    if (max({a,b,c})<=x) cout<<"YES\n";
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