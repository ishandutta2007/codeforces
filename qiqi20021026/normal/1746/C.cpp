#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> a(n+1);
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    vector<pair<int,int>> p;
    for (int i=n;i>=2;--i){
        a[i]=a[i-1]-a[i];
        p.push_back({a[i],i});
    }
    cout<<1;
    sort(p.begin(),p.end());
    for (auto [x,y]:p) cout<<' '<<y;
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();
}