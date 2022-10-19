#include<bits/stdc++.h>

using namespace std;

map<int,int> mp;

void solve(){
    int n; cin>>n;
    vector<int> a(n+1);
    mp.clear();
    int ans=n;
    int now=0;
    mp[0]=1;
    for (int i=1;i<=n;++i){
        cin>>a[i]; now^=a[i];
        if (mp[now]){
            --ans;
            mp.clear();
            now=0;
            mp[0]=1;
        }
        else{
            mp[now]=1;
        }
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();

    return 0;
}