#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

void solve(){
    int n; cin>>n;
    vector<int> a(n+1);
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    int s=(1<<30)-1;
    int i=1;
    for (;i<=n;++i){
        bool fl=0;
        for (int j=i;j<=n;++j){
            if (a[j]&s) fl=1;
            if ((a[j]&s)>(a[i]&s)){
                swap(a[i],a[j]);
            }
        }
        if (!fl) break;
        cout<<a[i]<<' ';
        s^=a[i]&s;
    }
    for (;i<=n;++i) cout<<a[i]<<' ';
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    LL T; cin>>T;
    while (T--){
        solve();
    }
}