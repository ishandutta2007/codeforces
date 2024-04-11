#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n,m; cin>>n>>m;
    int sum=0;
    vector<int> a(n+1);
    for (int i=1;i<=n;++i){
        cin>>a[i];
        sum+=a[i];
    }
    if (sum==0){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();
}