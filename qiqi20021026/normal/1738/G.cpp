#include<bits/stdc++.h>

using namespace std;

#define N 1005

int n,m,f[N][N],a[N][N];

void solve(){
    cin>>n>>m; --m;
    for (int i=1;i<=n;++i){
        string s; cin>>s;
        for (int j=0;j<n;++j){
            a[i][j+1]=!(s[j]-'0');
        }
    }
    for (int i=1;i<=m;++i){
        for (int j=1;j<=m-i+1;++j) a[i][n-j+1]=a[n-j+1][i]=1;
    }
    for (int i=n;i;--i){
        for (int j=n;j;--j){
            f[i][j]=max(f[i+1][j+1]+a[i][j],max(f[i+1][j],f[i][j+1]));
        }
    }
    if (f[1][1]>m){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            cout<<(f[i][j]!=f[i+1][j+1]);
        }
        cout<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    while (T--) solve();
}