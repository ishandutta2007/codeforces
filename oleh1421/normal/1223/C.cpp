#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
///#define int long long
typedef long long ll;
using namespace std;
ll p[300001];
ll x,a,y,b,k;
bool ok(int m){
    int cnta=0;
    int cntb=0;
    int cntab=0;
    for (int i=1;i<=m;i++){
        if (i%a==0 && i%b==0) cntab++;
        else if (i%a==0) cnta++;
        else if (i%b==0) cntb++;
    }

    vector<ll>v;
    ll sum=0ll;
    for (int i=0;i<m;i++){
        if (i<cntab) sum+=(p[i]*(x+y))*1ll;
        else if (i<cnta+cntab) sum+=(p[i]*x)*1ll;
        else if (i<cntab+cnta+cntb) sum+=(p[i]*y)*1ll;
        if (sum>=k) return true;
    }
    return false;
}
void solve(){
    int n;cin>>n;
    for (int i=0;i<n;i++) cin>>p[i],p[i]/=100;
    cin>>x>>a>>y>>b;
    if (x<y){
        swap(x,y);
        swap(a,b);
    }
    cin>>k;
    sort(p,p+n);
    reverse(p,p+n);
    int l=1;
    int r=n;
    if (!ok(n)){
        cout<<"-1\n";
        return;
    }
    while (r-l>1){
        int m=(l+r)/2;
        if (ok(m)) r=m;
        else l=m;
    }
    if (ok(l)) cout<<l<<endl;
    else cout<<r<<endl;
    /*int cnta=0;
    int cntb=0;
    int cntab=0;
    for (int i=1;i<=n;i++){
        if (i%a==0 && i%b==0) cntab++;
        else if (i%a==0) cnta++;
        else if (i%b==0) cntb++;
    }

    vector<ll>v;
    ll sum=0ll;
    for (int i=0;i<n;i++){
        if (i<cntab) sum+=(p[i]*(x+y))*1ll;
        else if (i<cnta+cntab) sum+=(p[i]*x)*1ll;
        else if (i<cntab+cnta+cntb) sum+=(p[i]*y)*1ll;
        cout<<sum<<endl;
        if (sum>=k){
            cout<<i+1<<endl;
            return;
        }
    }
    cout<<"-1\n";*/

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
/*



*/