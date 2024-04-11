#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
///#define int ll
using namespace std;
mt19937_64 rnd((unsigned) chrono::steady_clock::now().time_since_epoch().count());
const int N=1500010;
const ll inf=1000000000000000001ll;
const ll mod=998244353;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (n<=2){
        cout<<0<<endl;
        return;
    }
    int res=2;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            int last=j;
            int cnt=0;
            for (int t=1;t<=n;t++){
                if ((a[t]-a[i])*(j-i)==(a[j]-a[i])*(t-i)) cnt++;
            }
            res=max(res,cnt);
        }
    }
    cout<<n-res<<endl;
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




**/