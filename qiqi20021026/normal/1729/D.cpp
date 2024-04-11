#include<bits/stdc++.h>

using namespace std;

int a[120000];

void solve(){
    int n; cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    for (int i=1;i<=n;++i){
        int x; cin>>x;
        a[i]=x-a[i];
    }
    sort(a+1,a+n+1);
    int ans=0;
    for (int l=1,r=n;l<r;){
        if (a[l]+a[r]>=0){
            ++l; --r; ++ans;
        }
        else ++l;
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();
    return 0;   
}