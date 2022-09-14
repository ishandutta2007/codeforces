#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#define endl '\n'
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
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        can[a][b]=can[b][a]=true;
    }
    dp0[(1<<10)-1]=1;
    for (int mask=0;mask<(1<<10);mask++){
        for (int i=0;i<10;i++){
            if (mask&(1<<i)){
                int nw=0;
                for (int j=0;j<10;j++){
                    if (can[i][j]){
                        if (i<=j && mask&(1<<j)) nw|=(1<<j);
                    } else {
                        nw|=(1<<j);
                    }
                }
                go[mask][i]=nw;
            }
        }
    }
    for (int i=1;i<n;i++){
        for (int mask=0;mask<(1<<10);mask++){
            for (int j=0;j<10;j++) dp1[go[mask][j]]+=dp0[mask];
        }
        for (int mask=0;mask<(1<<10);mask++){
            dp0[mask]=dp1[mask]%mod;
            dp1[mask]=0;
        }
    }
    ll res=0ll;
    for (int mask=0;mask<(1<<10);mask++){
        res+=dp0[mask]*__builtin_popcount(mask);
        res%=mod;
    }
    cout<<res<<endl;

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;

    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}

/**

**/