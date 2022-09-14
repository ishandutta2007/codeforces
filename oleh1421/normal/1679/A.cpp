//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=50105;
const ll inf=2e18;
const ll mod=998244353;
bool can[10][10];
ll dp0[(1<<10)];
ll dp1[(1<<10)];
int go[(1<<10)][10];
void solve(int Case){
    ll n;cin>>n;
    if (n%2 || n<4){
        cout<<-1<<endl;
        return;
    }
    n/=2;
    cout<<(n+2)/3<<" "<<n/2<<endl;


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