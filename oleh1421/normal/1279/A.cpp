#include <bits/stdc++.h>
#define endl '\n'
const long long mod=1000000007;
typedef long long ll;
using namespace std;
mt19937_64 rng(time(NULL));
void solve(){
    int a,b,c;cin>>a>>b>>c;
    if (a>b+c+1 || b>a+c+1 || c>a+b+1) cout<<"No\n";
    else cout<<"Yes\n";
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