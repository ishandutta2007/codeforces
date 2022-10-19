#include<bits/stdc++.h>

using namespace std;

int n,a[3000];

int calc(int sum){
    int t=0,k=0,ret=0;
    for (int i=1;i<=n;++i){
        t+=a[i];
        ++k;
        ret=max(ret,k);
        if (t>sum) return n+1;
        if (t==sum) t=k=0;
    }
    if (t) return n+1;
    return ret;
}
void solve(){
    cin>>n;
    for (int i=1;i<=n;++i) cin>>a[i];
    int ans=n+1;
    for (int i=1;i<=n;++i){
        int sum=0;
        for (int j=1;j<=i;++j) sum+=a[j];
        ans=min(ans,calc(sum));
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();
}