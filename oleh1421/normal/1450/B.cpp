#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
#define int ll
const int N=500010;
int x[N],y[N];
void solve(){
    int n;cin>>n;
    int k;cin>>k;

    for (int i=1;i<=n;i++) cin>>x[i]>>y[i];
    for (int i=1;i<=n;i++){
        int cnt=0;
        for (int j=1;j<=n;j++){
            if (abs(x[i]-x[j])+abs(y[i]-y[j])<=k) cnt++;
        }
        if (cnt==n){
            cout<<1<<endl;
            return;
        }
    }
    cout<<-1<<endl;
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