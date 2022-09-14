#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=500010;
ll a[N];
void solve(){
    ll n;cin>>n;
    ll sum=0ll;
    ll mx=0ll;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        mx=max(mx,a[i]);
    }

    cout<<max({0ll,mx*(n-1)-sum,(n-1-(sum%(n-1ll))%(n-1ll))%(n-1ll)})<<endl;


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
/*

mx*(n-1)<=s
*/