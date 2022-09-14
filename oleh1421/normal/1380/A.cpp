//#pragma GCC optimize("trapv")
///SOLVE ACMP PROBLEM
#include <bits/stdc++.h>
#define y1 y_1
#define endl '\n'
typedef long long ll;
//#define int ll
using namespace std;
const int N=500010;
int p[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i];
    for (int i=2;i<n;i++){
        if (p[i]>p[i-1] && p[i]>p[i+1]){
            cout<<"YES\n";
            cout<<i-1<<" "<<i<<" "<<i+1<<endl;
            return;
        }
    }
    cout<<"NO\n";

}
int32_t main()
{
//    freopen("cosmo.in","r",stdin);
//    freopen("cosmo.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}