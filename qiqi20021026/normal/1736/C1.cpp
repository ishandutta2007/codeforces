#include<bits/stdc++.h>

using namespace std;

#define N 300'000

int a[N];

void solve(){
    int n; cin>>n;
    for (int i=1;i<=n;++i) cin>>a[i];
    for (int i=1;i<=n;++i){
        a[i]=i+1-a[i];
    }
    int t=1;
    long long ans=0;
    for (int i=1;i<=n;++i){
        for (;t<i;++t);
        for (;t<=n&&i>=a[t];++t);
        ans+=t-i;
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();
}