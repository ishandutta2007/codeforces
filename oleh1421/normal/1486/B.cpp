//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=200010;
const ll inf=10000000000007ll;
const int A=1000100;
ll x[N],y[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>x[i]>>y[i];
    sort(x+1,x+n+1);
    sort(y+1,y+n+1);
    if (n%2) cout<<1<<endl;
    else cout<<(y[n/2+1]-y[n/2]+1ll)*(x[n/2+1]-x[n/2]+1ll)<<endl;

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