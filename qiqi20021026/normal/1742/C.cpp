#include<bits/stdc++.h>

using namespace std;

void solve(){
    bool fl=0;
    for (int i=0;i<8;++i){
        string st; cin>>st;
        if (st==string(8,'R')){
            fl=1;
        }
    }
    cout<<(fl?"R":"B")<<'\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--){
        solve();
    }
}