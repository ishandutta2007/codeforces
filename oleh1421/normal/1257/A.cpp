#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
//#define int long long
void solve(){
    int n,x,a,b;cin>>n>>x>>a>>b;
    cout<<min(n-1,abs(a-b)+x)<<endl;
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