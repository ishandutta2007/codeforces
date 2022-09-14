#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
typedef long double ld;
//#define int ll
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
const ll mod=998244353;
const ll inf=1000000000000000001;
const int N=300010;
ll a[N];
ll d[N];
void solve(){
    ll n,x;cin>>n>>x;
    for (int i=1;i<=n;i++) cin>>a[i];
    ll mn=a[1],mx=a[1];
    ll sum=0ll;
    for (int i=1;i<=n;i++){
        mn=min(mn,a[i]);
        mx=max(mx,a[i]);
        if (i>1) sum+=abs(a[i]-a[i-1]);
    }
    ll best1=min(abs(1-a[1]),abs(1-a[n])),best2=min(abs(x-a[1]),abs(x-a[n]));
    if (1>=mn) best1=0;
    if (x<=mx) best2=0;
    for (int i=2;i<=n;i++){
        best1=min(best1,abs(1-a[i-1])+abs(1-a[i])-abs(a[i]-a[i-1]));
        best2=min(best2,abs(x-a[i-1])+abs(x-a[i])-abs(a[i]-a[i-1]));
    }
    cout<<sum+best1+best2<<endl;

}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}

/**
  ,        .
**/