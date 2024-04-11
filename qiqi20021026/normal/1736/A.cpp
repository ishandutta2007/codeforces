#include<bits/stdc++.h>

using namespace std;

int cnt[2];

void solve(){
    int n; cin>>n;
    vector<int> a(n),b(n);
    for (auto &x:a) cin>>x;
    for (auto &x:b) cin>>x;
    cnt[0]=cnt[1]=0;
    for (int i=0;i<n;++i){
        if (a[i]!=b[i]) ++cnt[a[i]];
    }
    int ans=abs(cnt[0]-cnt[1]);
    if (cnt[0]&&cnt[1]) ++ans;
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();
}