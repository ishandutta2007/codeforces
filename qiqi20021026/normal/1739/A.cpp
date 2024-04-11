#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n,m; cin>>n>>m;
    if (n==1||m==1) cout<<"1 1\n";
    else cout<<"2 2\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();
}