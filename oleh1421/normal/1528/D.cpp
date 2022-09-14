#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=610;
const int inf=2e9;
int cost[N][N];
int d[N];
int n,m;
bool used[N];
int add[N];
int mn[N];
int mn1[N];
int ans[N][N];
void dij(int s){
    for (int i=0;i<n;i++) d[i]=inf,used[i]=false;
    d[s]=0;
    for (int it=1;it<=n;it++){
        int v=-1;
        int D=inf;
        for (int i=0;i<n;i++) if (!used[i]) D=min(D,d[i]);
        for (int i=0;i<n;i++) if (!used[i] && d[i]==D) v=i;
        used[v]=true;
        for (int j=0;j<n;j++) mn[j]=inf;
        int z=d[v]%n;
        for (int j=0;j<n-z;j++) mn[j+z]=cost[v][j];
        for (int j=n-z;j<n;j++){
            mn[j+z-n]=cost[v][j];
        }
        for (int j=1;j<n;j++) mn[j]=min(mn[j-1]+1,mn[j]);
        for (int to=0;to<n;to++){
            d[to]=min(d[to],d[v]+min(mn[to],mn[n-1]+to+1));
        }
    }
    for (int i=0;i<n;i++) ans[s][i]=d[i];
}
void solve(){
    cin>>n>>m;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cost[i][j]=inf;
        }
    }
    for (int i=1;i<=m;i++){
        int a,b,c;cin>>a>>b>>c;
        cost[a][b]=c;
    }
    for (int i=0;i<n;i++){
        dij(i);
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}