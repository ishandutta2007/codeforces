#include <bits/stdc++.h>

typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=500010;
const ll mod=1000000007;
int p[N],q[N];
int a[N];
bool used[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i];
    for (int i=1;i<=n;i++) cin>>q[i];


    for (int i=1;i<=n;i++){
        if (p[i]==q[i]){
            cout<<0<<endl;
            return;
        }
    }
    for (int i=1;i<=n;i++){
        a[p[i]]=q[i];
        used[i]=false;
    }
    ll res=1ll;

    for (int i=1;i<=n;i++){
        if (used[i]) continue;
        res*=2ll;
        res%=mod;
        int cur=i;
        while (!used[cur]){
            used[cur]=true;
            cur=a[cur];
        }
    }
    cout<<res<<endl;

}
int32_t main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}