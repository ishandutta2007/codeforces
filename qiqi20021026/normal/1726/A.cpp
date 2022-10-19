#include<bits/stdc++.h>

using namespace std;

#define N 10000

int n,a[N];

void solve(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        a[i+n]=a[i];
    }
    int ans=0;
    for (int i=2;i<=n;++i) ans=max(ans,(a[i]-a[1]));
    for (int i=1;i<n;++i) ans=max(ans,(a[n]-a[i]));
    for (int i=1;i<=n;++i){
        ans=max(ans,(a[i+n-1]-a[i]));
    }
    cout<<ans<<'\n';
}

int main(){
    int T; cin>>T;
    while (T--) solve();
}