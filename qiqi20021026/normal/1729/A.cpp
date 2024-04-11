#include<bits/stdc++.h>

using namespace std;

void solve(){
    int a,b,c; cin>>a>>b>>c;
    int a1=a-1;
    int a2=abs(c-b)+(c-1);
    cout<<(a1==a2?3:(a1>a2)+1)<<'\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();

    return 0;
}