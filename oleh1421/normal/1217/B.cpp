#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
///#define int long long
typedef long long ll;
using namespace std;
int d[20001];
int h[20001];
void solve(){
    int n,x;cin>>n>>x;
    for (int i=1;i<=n;i++) cin>>d[i]>>h[i];
    int maxx=0;
    int maxd=0;
    for (int i=1;i<=n;i++){
        maxx=max(maxx,d[i]-h[i]);
        maxd=max(maxd,d[i]);
        if (d[i]>=x){
            cout<<1<<endl;
            return;
        }
    }
    if (maxx==0){
        cout<<-1<<endl;
        return;
    }
    cout<<1+((x-maxd)/(maxx)+((x-maxd)%(maxx)>0))<<endl;
 
 
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}