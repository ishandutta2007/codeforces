#include<bits/stdc++.h>

using namespace std;

#define N 100

const int mod=998244353;
int n,f[2],C[N][N];

void upd(int &x,int y){x=(x+y)%mod;}

void solve(){
    int n; cin>>n;
    f[0]=f[1]=0;
    for (int i=0;i<n/2;++i){
        upd(f[i%2],C[n-i*2-1][n/2-i]);
        upd(f[(i%2)^1],C[n-i*2-2][n/2-i]);
    }
    cout<<f[0]<<' '<<f[1]<<' '<<1<<'\n';
}
void init(int n){
    for (int i=0;i<=n;++i){
        C[i][0]=1;
        for (int j=1;j<=i;++j){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    init(60);
    int T; cin>>T;
    while (T--) solve();
}