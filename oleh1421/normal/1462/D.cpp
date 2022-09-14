
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=200010;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int res=1;
    ll S=0ll;
    for (int i=1;i<n;i++){
        S+=a[i];
        ll sum=0ll;
        bool ok=true;
        int cnt=1;
        for (int j=i+1;j<=n;j++){
            sum+=a[j];
            if (sum>S){
                ok=false;
                break;
            } else if (sum==S) sum=0,cnt++;
        }
        if (ok && !sum) res=max(res,cnt);
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
//3 1 5 4 2 2
//3 1 1