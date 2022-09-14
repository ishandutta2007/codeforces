//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define endl '\n'
using namespace std;
const int N=1010;
const ll mod=998244353;
const ll inf=2e9;
int x[N],y[N];
#define int ll
int d[N][N];
int mn[N];
vector<int>order;
bool used[N];
int n;
void dfs(int v){
    used[v]=true;
    order.push_back(v);
    for (int to=1;to<=n;to++){
        if (used[to]) continue;
        if (mn[to]==d[v][to] && mn[v]==d[v][to]){
            dfs(to);
        }
    }
}
ll dp[N];
ll dp1[N];
ll f[N][N];
int c[N];
int ans=0;
void F(int pos){
    if (pos==n+1){
        bool ok=true;
        for (int a=1;a<=n;a++){
            for (int b=a+1;b<=n;b++){
                if (c[a]==c[b]){
                    for (int i=1;i<=n;i++){
                        if (i==a || i==b) continue;
                        if (c[a]==c[i]){
                            if (d[a][i]!=d[a][b] || d[b][i]!=d[a][b]){
                                ok=false;
                            }

                        } else {
                            if (d[a][i]<=d[a][b] || d[b][i]<=d[a][b]){
                                ok=false;
                            }
                        }
                    }
                }
            }
        }

        ans+=ok;
        return;
    }
    for (int i=1;i<=n;i++){
        c[pos]=i;
        F(pos+1);
        c[pos]=0;
    }
}
void solve(int Case){
    srand(time(NULL));
    cin>>n;
    for (int i=1;i<=n;i++){
        f[i][i-1]=1;
        for (int j=i;j<=n;j++){
            f[i][j]=(f[i][j-1]*j)%mod;
        }
    }

    for (int i=1;i<=n;i++) {
        cin>>x[i]>>y[i];
//        x[i]=i;
//        y[i]=0;
    }
    vector<pair<int,int> >R;
    for (int i=1;i<=n;i++){
        mn[i]=inf;
        for (int j=1;j<=n;j++){
            d[i][j]=abs(x[i]-x[j])+abs(y[i]-y[j]);
            if (i!=j) mn[i]=min(mn[i],d[i][j]);
        }
    }
//    cout<<mn[1]<<" "<<mn[3]<<" "<<mn[5]<<endl;
    dp[0]=1ll;
    for (int v=1;v<=n;v++){
        if (used[v]) continue;
        dfs(v);
        bool can=true;
        for (int i:order){
            for (int j:order){
                if (i==j) continue;
                if (d[i][j]>mn[v] || d[i][j]>mn[v]) can=false;
            }
        }
        for (int i:order){
            for (int j=1;j<=n;j++){
                if (d[i][j]==mn[v] && d[i][j]>mn[j]) can=false;
            }
        }
        vector<int>upd={order.size()};
        if (can && order.size()>1) upd.push_back(1);

        order.clear();
        for (int i=n;i>=0;i--){

            for (int x:upd){
                dp1[i]+=dp[i-x]*f[n-i+1][n-i+x];
                dp1[i]%=mod;

            }
        }
        for (int i=0;i<=n;i++){
            dp[i]=dp1[i];
            dp1[i]=0;
        }

    }
    ll res=0ll;
    for (int i=1;i<=n;i++) res=(res+dp[i])%mod;
//    if (ans!=res) exit(1);
    cout<<res<<endl;

}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
//    cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}
/**
5
5 2
7 0
6 7
0 5
10 9

**/