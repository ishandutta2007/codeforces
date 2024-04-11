#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1000010;
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        int x;cin>>x;
        m-=x;
    }
    if (m) cout<<"NO\n";
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