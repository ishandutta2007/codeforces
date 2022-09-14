//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=2000000000000000001ll;
const ll mod=1000000007;
using namespace std;
mt19937 rnd(time(NULL));
const int N=500010;
ll a[N];
void solve(){
    ll n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    ll res=-inf;
    for (ll i=n;i>=max(1ll,n-k*2-1);i--){
        for (ll j=i-1;j>=max(1ll,n-k*2-1);j--){
            res=max(res,i*j-k*(a[i]|a[j]));
        }
    }
    cout<<res<<endl;
}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}