#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

LL f[200][200];

LL calc(LL n,LL m,LL t){
    memset(f,0,sizeof f);
    f[0][0]=t;
    for (LL i=0;i<=n;++i){
        for (LL j=0;j<=m;++j){
            f[i][j+1]+=(f[i][j]+1)/2;
            f[i+1][j]+=f[i][j]/2;
        }
    }
    return f[n][m];
}

void solve(){
    LL n,m,t; cin>>t>>n>>m;
    LL x=n+m;
    if (x>t){cout<<"NO\n"; return;}
    cout<<((calc(n,m,t-x+1)-calc(n,m,t-x))?"YES":"NO")<<'\n';
}

int main(){
    int T; cin>>T;
    while (T--) solve();
    
    return 0;
}