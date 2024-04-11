#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
typedef long double ld;
const int N=510;
const int M=N*N;
const ll inf=1e18;
//<pair<int,ll> >g[N];
int a[M],b[M];
ll w[M];
int d[N][N];
ll D[N][N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            d[i][j]=N;
        }
    }
    for (int i=1;i<=n;i++) d[i][i]=0;
    for (int i=1;i<=m;i++){
        cin>>a[i]>>b[i]>>w[i];

        d[a[i]][b[i]]=1;
        d[b[i]][a[i]]=1;
//        g[a[i]
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            for (int k=1;k<=n;k++){
                d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
            }
        }
    }
    ll res=inf;
    for (int i=1;i<=m;i++){
        res=min(res,w[i]*(1ll+d[a[i]][1]+d[b[i]][n]));
        res=min(res,w[i]*(1ll+d[a[i]][n]+d[b[i]][1]));
        for (int x=1;x<=n;x++){
            res=min(res,w[i]*(1ll+d[1][x]+d[x][n]+min(d[a[i]][x],d[b[i]][x])+1ll));
        }
    }
    cout<<res<<'\n';
//    for (int i=1;i<=m;i++){
//        D[a[i]][b[i]]=min(D[a[i]][b[i]],w[i]);
//        D[b[i]][a[i]]=min(D[b[i]][a[i]],w[i]);
//    }
    /////////////////////

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}

/**


**/