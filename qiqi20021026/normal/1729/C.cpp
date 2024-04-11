#include<bits/stdc++.h>

using namespace std;

void solve(){
    string st; cin>>st;
    vector<int> c[30];
    for (int i=0;i<st.size();++i){
        c[st[i]-'a'].push_back(i+1);
    }
    int x=st[0]-'a',y=st[st.size()-1]-'a';
    cout<<abs(y-x)<<' ';
    vector<int> ans;
    for (int i=x;i!=y;i+=(y-x)/abs(y-x)){
        for (int j:c[i]) ans.push_back(j);
    }
    for (int j:c[y]) ans.push_back(j);
    cout<<ans.size()<<'\n';
    for (int i:ans) cout<<i<<' '; cout<<'\n';
}

int main(){
    int T; cin>>T;
    while (T--) solve();

    return 0;
}