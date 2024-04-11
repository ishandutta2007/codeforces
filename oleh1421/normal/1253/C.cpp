#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const ll mod=1000000007;
ll a[200001];
ll s[200001];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll sum=0ll;
    for (int i=1;i<=n;i++){
        sum+=a[i];
        sum+=s[i%m];
        s[i%m]+=a[i];
        cout<<sum<<" ";
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt=1;
    while (tt--){
        solve();
        cout<<endl;
    }
    return 0;
}