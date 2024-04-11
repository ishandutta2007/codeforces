#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=100010;
int a[N];
double p[N];
int r[N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) cin>>r[i]>>p[i];
    int R=n+1;
    for (int i=n;i>=1;i--){
        if (a[i]!=i) break;
        R=i;
    }
    R--;
    double res=1.0;
    if (R==0){
        res=0.0;
    }

    for (int i=1;i<=m;i++){
        if (r[i]>=R){
            res*=1.0-p[i];
        }
    }
    cout<<setprecision(10)<<fixed<<1.0-res<<endl;
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