#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

LL s[2][30];
LL pd(){
    for (int i=0;i<26;++i){
        if (s[0][i]>0){
            for (int j=i+1;j<26;++j){
                if (s[1][j]>0) return 1;
            }
            if (s[1][i]<s[0][i]) return 0;
            bool fl=0;
            for (int j=i+1;j<26;++j){
                if (s[0][j]>0) fl=1;
            }
            if (s[1][i]>s[0][i]){
                if (fl) return 0;
                return 1;
            }
            if (fl) return 0;
            for (int j=0;j<i;++j){
                if (s[1][j]>0) return 1;
            }
        }
    }
    return 0;
}
void solve(){
    int m; cin>>m;
    memset(s,0,sizeof s);
    s[0][0]=s[1][0]=1;
    while (m--){
        int op,k; string st;
        cin>>op>>k>>st;
        --op;
        for (auto x:st){
            int w=x-'a';
            s[op][w]+=k;
        }
        cout<<(pd()?"YES":"NO")<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    LL T; cin>>T;
    while (T--){
        solve();
    }
}