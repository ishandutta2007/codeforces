#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> a(n+1);
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    int l=1,r=n,ans=0;
    while (l<r){
        if (a[l]==0){++l; continue;}
        if (a[r]==1){--r; continue;}
        ++l; --r;
        ++ans;
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();
}