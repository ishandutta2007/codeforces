#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
mt19937 rnd(time(NULL));
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N=500010;
const ll mod=1000000007;
ll a[N],b[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    ll res=0ll;
    for (int i=1;i<n;i++){
        res+=min(abs(a[i]-a[i+1])+abs(b[i]-b[i+1]),abs(a[i]-b[i+1])+abs(a[i+1]-b[i]));
    }
    cout<<res<<endl;
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
/**
1000000000

3 4 8


3 12 24

19

**/