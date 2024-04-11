#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=2000000000000000001;
const ll mod=998244353;
using namespace std;
mt19937 rnd(time(NULL));
const int N=100010;
ll a[2][N];
void solve(){
    int n;cin>>n;
    for (int i=0;i<2;i++){
        for (int j=1;j<=n;j++) cin>>a[i][j],a[i][j]+=a[i][j-1];
    }
    ll res=inf;
    for (int i=1;i<=n;i++){
        res=min(res,max(a[1][i-1],a[0][n]-a[0][i]));
    }
    cout<<res<<endl;


}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/**
1
8 5
2 1 7 4
4 2
**/