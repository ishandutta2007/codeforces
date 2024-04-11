#include<bits/stdc++.h>

using namespace std;

string s[4][1005];

int main(){
    int T; cin>>T;
    while (T--){
        int n; cin>>n;
        map<string,int> cnt;
        for (int i=1;i<=3;++i){
            for (int j=1;j<=n;++j){
                cin>>s[i][j];
                ++cnt[s[i][j]];
            }
        }
        for (int i=1;i<=3;++i){
            int ans=0;
            for (int j=1;j<=n;++j){
                if (cnt[s[i][j]]==1) ans+=3;
                if (cnt[s[i][j]]==2) ++ans;
            }
            cout<<ans<<' ';
        }
        cout<<'\n';
    }
}