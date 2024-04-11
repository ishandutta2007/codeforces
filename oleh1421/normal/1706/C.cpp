#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#define y2 y_2
//#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
//#define int ll
typedef long long ll;
typedef long double ld;
const int N=300100;
const int Q=3000100;
const ll mod=998244353;
const int inf=2e9;
const int Lg=30;
mt19937_64 rnd(time(NULL));
int a[N];
int p[N];
const int c=70;
ll pref[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (n%2){
        ll res=0ll;
        for (int i=2;i<n;i+=2){
            res+=max({0,a[i-1]-a[i]+1,a[i+1]-a[i]+1});
        }
        cout<<res<<'\n';
        return;
    }
    for (int i=2;i<=n-2;i+=2){
        pref[i]=pref[i-2];
        pref[i]+=max({0,a[i-1]-a[i]+1,a[i+1]-a[i]+1});
    }
    ll res=pref[n-2];
    ll sum=0ll;
    for (int i=n-1;i>=3;i-=2){
        sum+=max({0,a[i-1]-a[i]+1,a[i+1]-a[i]+1});
        res=min(res,sum+pref[i-3]);
    }
    cout<<res<<'\n';






}
int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**

5 5 5
1 2
1 3
2 4
3 4
3 5

1 4
3 4
2 2
2 5
3 5


**/