#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
void solve(){
    int n,d;cin>>n>>d;
    int g=sqrt(d);
    for (int x=max(g-1000,0);x<=min(g+1000,n);x++){
        if (x+(d+x)/(x+1)<=n){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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