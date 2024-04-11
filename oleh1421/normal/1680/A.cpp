//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=500010;
const ll inf=2e18;
const ll mod=1000000007;

void solve(int Case){
    int l1,r1,l2,r2;cin>>l1>>r1>>l2>>r2;
    int res=l1+l2;
    if (max(l1,l2)<=min(r1,r2)) res=min(res,max(l1,l2));
    cout<<res<<endl;


}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}

/**

**/