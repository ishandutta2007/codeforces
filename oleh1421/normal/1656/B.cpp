#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
const int N=2000010;
const ll mod=1000000007;
const int L=20;
const ll inv2=(mod+1)/2;
ll a[N];
void solve(){
    int n;cin>>n;
    ll k;cin>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        int ind=lower_bound(a+1,a+n+1,a[i]-k)-a;
        if (ind<=n && a[ind]==a[i]-k){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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

//2
//
//1 2

/**



**/