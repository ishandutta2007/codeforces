#include<bits/stdc++.h>

using namespace std;

bool vis[120000];

void solve(){
    int n; string st;
    cin>>n>>st;
    stack<int> stk; stk.push(0);
    int ans=0,cnt=0;
    for (int i=0;i<n*2;++i){
        if (st[i]=='('){
            int x=stk.top();
            if (!vis[x]){vis[x]=1; ++ans;}
            stk.push(++cnt);
        }
        else{
            stk.pop();
        }
    }
    for (int i=0;i<=n;++i) vis[i]=0;
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();

    return 0;
}