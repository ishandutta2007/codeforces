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
    ll n;cin>>n;
    ll p=1ll;
    while (n%p==0) p*=2ll;
    ll x=(2ll*n)/p;
    if (x==1){
        cout<<-1<<endl;
        return;
    }
    cout<<min(p,x)<<endl;
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