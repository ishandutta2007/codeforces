#include<bits/stdc++.h>

using namespace std;

int cnt[2],a[120'000],b[120'000];

void solve(){
    int n; cin>>n;
    for (int i=1;i<=n;++i) cin>>a[i];
    a[0]=a[n+1]=1;
    for (int i=1;i<=n+1;++i){
        b[i]=lcm(a[i],a[i-1]);
    }
    for (int i=1;i<=n;++i){
        if (gcd(b[i],b[i+1])!=a[i]){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();
}