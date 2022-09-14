#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
void solve(){
    ll x,y,k;cin>>x>>y>>k;
    cout<<(k+y*k-3+x)/(x-1)+k<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();

    }
    return 0;
}