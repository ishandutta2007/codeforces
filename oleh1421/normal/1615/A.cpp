#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1000100;
const ll mod=998244353;
void solve(){
    int n;cin>>n;
    ll sum=0ll;
    for (int i=1;i<=n;i++){
        ll x;cin>>x;
        sum+=x;
    }
    cout<<((sum%n)>0)<<endl;
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
/**




**/