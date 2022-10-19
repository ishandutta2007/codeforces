#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; string st;
    cin>>n>>st; st=st+'*';
    for (int i=0;i<st.size()-1;++i){
        int num=0;
        if (i+2<st.size()&&st[i+2]=='0'&&st[i+3]!='0'){
            num=atoi(st.substr(i,2).c_str());
            i=i+2;
        }
        else{
            num=st[i]-'0';
        }
        cout<<(char)('a'+num-1);
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();

    return 0;
}