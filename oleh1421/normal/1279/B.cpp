#include <bits/stdc++.h>
#define endl '\n'
const long long mod=1000000007;
typedef long long ll;
using namespace std;
mt19937_64 rng(time(NULL));
int a[3000001];
void solve(){
    int n,s;cin>>n>>s;
    for (int i=1;i<=n;i++) cin>>a[i];
    int maxx=0;
    int res=0;
    ll sum=0ll;
    int ans=0;
    for (int i=1;i<=n;i++){
        if (a[maxx]<a[i]) maxx=i;
        sum+=a[i]*1ll;
        if (sum<=s) {
            if (res<i){
                res=i;
                ans=0;
            }
        }
        if (sum-a[maxx]<=s) {
            if (i-1>res){
                res=i-1;
                ans=maxx;
            }
        }
    }
    cout<<ans<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}