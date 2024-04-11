#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int x[200002];
void solve(){
    ll n,a,b;cin>>n>>a>>b;
    string s;cin>>s;
    vector<ll>v;
    for (int i=0;i<=n;i++) x[i]=0;
    for (int i=0;i<n;i++){
        if (s[i]=='1') {
            x[i]=1;
            x[i+1]=1;
        }
    }
    for (int i=0;i<=n;i++) if (x[i]) v.push_back(i);
    if (v.empty()){
        cout<<n*a+(n+1ll)*b<<endl;
        return;
    }
    ll res=0ll;
    res+=(v[0]+1ll)*a+(v[0]+2ll)*b;
    for (int i=1;i<v.size();i++){
        if (v[i]==v[i-1]+1){
            res+=a+b+b;
        } else {
            res+=min((v[i]-v[i-1])*1ll*a+(v[i]-v[i-1])*2ll*b,(v[i]-v[i-1]+1)*1ll*b+(v[i]-v[i-1]+2)*1ll*a)*1ll;
        }
    }
    res+=(n-v.back()+1ll)*a+(n-v.back())*b;
    cout<<res<<endl;

}
int32_t main() {
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}


///20075213641185