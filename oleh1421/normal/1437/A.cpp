#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=2010;
const int inf=1000000001;
void solve(){
    int l,r;cin>>l>>r;
    if (l*2<=r) cout<<"NO\n";
    else cout<<"YES\n";
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