#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//#define y2 y_2
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
#define int ll
typedef long long ll;
typedef long double ld;
const int N=2000010;

void solve(){
    int x,a,b,c;cin>>x>>a>>b>>c;
    if (a==1 || b==2 || c==3){
        cout<<"NO\n";
        return;
    }
    if (a==3 && c==1){
        cout<<"NO\n";
        return;
    }
    if (a==2 && b==1){
        cout<<"NO\n";
        return;
    }
    if (b==3 && c==2){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";

}
int32_t main() {
//    freopen("5.034.in","r",stdin);
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
4 3 2000
1 2 100
2 3 1000
2 4 1000
1.27
3,16,27,24,23,46
**/