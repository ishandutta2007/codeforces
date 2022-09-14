#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
///#define int ll
using namespace std;
mt19937_64 rnd((unsigned) chrono::steady_clock::now().time_since_epoch().count());
double random_double(){
    return rnd()%1000000001/1000000000.0;
}
const int N=550;
ll a[N][N];

void solve(){
    int n;cin>>n;
    for (int i=1;i<=n*2;i++){
        for (int j=1;j<=n*2;j++){
            cin>>a[i][j];
        }
    }
    ll res=0ll;
    for (int i=n+1;i<=n*2;i++){
        for (int j=n+1;j<=n*2;j++){
            res+=a[i][j];
            a[i][j]=0;
        }
    }

    res+=min({a[1][n+1],a[n+1][1],a[n][n+1],a[n+1][n],a[1][2*n],a[n][2*n],a[2*n][1],a[2*n][n]});
    cout<<res<<endl;
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
/**
2
0 0 4 2
0 0 2 4
4 2 4 2
2 4 2 4

**/