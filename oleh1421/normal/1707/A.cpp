//#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#define y2 y_2
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
//#define int ll
typedef long long ll;
typedef long double ld;
const int N=553010;
const ll mod=998244353;
const int inf=2e9;
const int Lg=30;
mt19937_64 rnd(time(NULL));
int a[N];
bool take[N];
void solve(){
    int n,q;cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>a[i],take[i]=false;
    if (q>=n){
        for (int i=1;i<=n;i++) cout<<1;
        cout<<endl;
        return;
    }
//    for (int i=1;i<=n;i++) a[i]=min(a[i],q+1);
    int L=0,R=n;
    while (R-L>1){
        int mid=(L+R)/2;
        int cur=q;
        for (int i=mid;i<=n;i++){
            if (cur<a[i]) cur--;
        }
        if (cur<0) L=mid;
        else R=mid;
    }
    for (int i=1;i<=n;i++){
        if (i<R){
            if (a[i]<=q) cout<<1;
            else cout<<0;
        } else cout<<1;
    }
    cout<<endl;





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
13 4
5 6 7 8 9 10 11 12 13 1 2 3 4
5 6 7 8 1 10 11 12 13 2 3 4 9

**/