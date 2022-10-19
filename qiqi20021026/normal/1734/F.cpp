#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

LL f[80][2][2][2];

void solve(){
    LL n,m; cin>>n>>m;
    --m;
    memset(f,0,sizeof f);
    f[0][0][0][0]=1;
    for (LL i=0;i<=60;++i){
        LL b=m>>i&1,t=n>>i&1;
        for (LL u:{0,1}){
            for (LL x:{0,1}){
                for (LL jw:{0,1}){
                    for (LL fl:{0,1}){
                        LL v=u+t+jw;
                        LL njw=v>>1;
                        v&=1;
                        LL nx=x^u^v;
                        LL nfl=u!=b?u>b:fl;
                        f[i+1][nx][njw][nfl]+=f[i][x][jw][fl];
                    }
                }
            }
        }
    }
    cout<<f[61][1][0][0]<<'\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    LL T; cin>>T;
    while (T--) solve();

    return 0;
}