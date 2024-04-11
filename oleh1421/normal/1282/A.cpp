#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
void solve(){
    ll a,b,c,r;cin>>a>>b>>c>>r;
    if (a>b) swap(a,b);
    if (abs(a-c)<=r && abs(b-c)<=r) cout<<0<<endl;
    else if (abs(a-c)<=r) cout<<b-c-r<<endl;
    else if (abs(b-c)<=r) cout<<c-r-a<<endl;
    else if (c-r>=a && c+r<=b) cout<<c-r-a+b-c-r<<endl;
    else cout<<b-a<<endl;
}
int main()
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