#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; string st;
    cin>>n>>st;
    st="*"+st;
    int cnt=0;
    for (int i=1;i<=n*2;++i){
        cnt^=st[i]-'0';
    }
    if (cnt){
        cout<<-1<<'\n';
        return;
    }
    vector<int> vec;
    for (int i=1,j=n;i<=n;++i){
        int x=i*2-1;
        if (st[x]!=st[x+1]){
            if (st[x]==st[n*2]){
                vec.push_back(x+1);
                swap(st[x+1],st[n*2]);
            }
            else{
                vec.push_back(x);
                swap(st[x],st[n*2]);
            }
        }
    }
    cout<<(vec.size()+1)<<' ';
    for (int i:vec) cout<<i<<' ';
    cout<<n*2<<'\n';
    for (int i=1;i<=n;++i) cout<<i*2<<" \n"[i==n];
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();
}