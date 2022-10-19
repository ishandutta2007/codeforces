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
    for (int i=0;i<n;++i){
        cin>>a[i];
        --a[i];
    }
    int cnt=0;
    for (int i=0;1<<i<n;++i){
        int t=1<<i;
        for (int j=0;j<n;j+=t<<1){
            int k=j+t;
            if (a[j]>a[k]){
                ++cnt;
                swap(a[j],a[k]);
            }
            if (a[k]-a[j]!=t){
                cout<<"-1\n";
                return;
            }
        }
    }
    cout<<cnt<<'\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();
}