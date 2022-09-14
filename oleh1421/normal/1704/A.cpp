//#pragma GCC optimize("Ofast")
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
const ll inf=2e18;
const ll mod=1000000007;
const ll mod1=mod*mod;
const int N=2000100;
int a[N],b[N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        a[i]=(c-'0');
    }
    for (int i=1;i<=m;i++){
        char c;cin>>c;
        b[i]=(c-'0');
    }
    for (int i=2;i<=m;i++){
        if (b[i]!=a[n-m+i]){
            cout<<"NO\n";
            return;
        }
    }
    for (int i=1;i<=n-m+1;i++){
        if (a[i]==b[1]){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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
//CRES
/**
2 3
1 2
2 1
0 0

**/