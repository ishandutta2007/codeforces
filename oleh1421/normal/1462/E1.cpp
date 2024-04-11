
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=200010;
const ll mod=10000000007ll;
int a[N];
void solve(){
    int n,m,k;cin>>n;
    m=3,k=2;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll res=0ll;
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        int r=upper_bound(a+1,a+n+1,a[i]+k)-a-1;
//        cout<<i<<" "<<r<<endl;
        ll cnt=r-i;
        res+=cnt*(cnt-1ll)/2ll;
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
//3 1 5 4 2 2
//3 1 1