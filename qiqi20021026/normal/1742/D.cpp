#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> f(1005);
    int a1=0,a2=0;
    for (int i=1;i<=n;++i){
        int x; cin>>x;
        f[x]=i;
        if (x==1){
            a2=a1; a1=i;
        }
    }
    int m=1000,ans=-1;
    if (a1&&a2) ans=a1+a2;
    for (int i=1;i<=m;++i){
        for (int j=1;j<=m;++j){
            if (f[i]&&f[j]&&gcd(i,j)==1){
                ans=max(ans,f[i]+f[j]);
            }
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--){
        solve();
    }
}