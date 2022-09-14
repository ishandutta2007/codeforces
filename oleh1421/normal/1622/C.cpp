#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
const int N=300010;
const ll mod=998244353;
ll a[N];
void solve(){
    int n;cin>>n;
    ll k;cin>>k;
    ll tot=0ll;
    for (int i=1;i<=n;i++) cin>>a[i],tot+=a[i];

    sort(a+1,a+n+1);
    reverse(a+2,a+n+1);

    ll res=tot;
    ll sum=0ll;
    for (ll i=1;i<=n;i++){
        sum+=a[i];
//        tot-sum+(mn-x)*i<=k
//        x>=
        res=min(res,i-1+max((tot-sum+a[1]*i-k+i-1)/i,0ll));
    }
    cout<<res<<endl;


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
/**




**/