#include<bits/stdc++.h>

using namespace std;

int n,a[1<<20];

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
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    vector<int> f(n+1);
    f[0]=1;
    for (int i=1;i<=n;++i){
        int j=i-a[i];
        if (j>=1) f[i]|=f[j-1];
        j=i+a[i];
        if (j<=n) f[j]|=f[i-1];
    }
    cout<<(f[n]?"YES":"NO")<<'\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();
}