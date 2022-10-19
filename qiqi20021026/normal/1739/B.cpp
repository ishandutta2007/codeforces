#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin>>n;
    int s=0;
    vector<int> ans;
    bool fl=0;
    for (int i=1;i<=n;++i){
        int x; cin>>x;
        if (x>0&&s-x>=0) fl=1;
        ans.push_back(s+=x);
    }
    if (fl) cout<<"-1\n";
    else{for (int i:ans) cout<<i<<' '; cout<<'\n';}
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();
}