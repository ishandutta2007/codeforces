#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=155;
int a[N];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (k==1){
        if (a[1]<a[n]) cout<<-1<<endl;
        else cout<<1<<endl;
        return;
    }
    int cnt=1;
    for (int i=2;i<=n;i++){
        cnt+=(a[i]!=a[i-1]);
    }
    if (cnt<=k){
        cout<<1<<endl;
        return;
    }
    cout<<(cnt-2)/(k-1)+1<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}