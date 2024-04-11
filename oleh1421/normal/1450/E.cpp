#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=2010;
vector<pair<int,int> >g[N];
int a[N],b[N],c[N];
int used[N];
int mn[N],mx[N];
int timer=0;
void dfs(int v){
    used[v]=++timer;
    for (auto cur:g[v]){
        int to=cur.first;
        int mn_w,mx_w;
        if (cur.second){
            mn_w=mx_w=cur.second;
        } else {
            mn_w=-1,mx_w=1;
        }
        if (!used[to]){
            mn[to]=mn[v]+mn_w;
            mx[to]=mx[v]+mx_w;
            dfs(to);
        } else if (used[to]<used[v] && (mn[v]+mn_w-mn[to]>0 || mx[v]+mx_w-mx[to]<0 || (mx[v]+mx_w-mx[to])%2)){
            cout<<"NO\n";
            exit(0);
        }
    }
}
int d[N][N];
int ans[N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++) cin>>a[i]>>b[i]>>c[i];
    for (int i=1;i<=m;i++){
        if (c[i]){
            g[a[i]].push_back({b[i],1});
            g[b[i]].push_back({a[i],-1});
        } else {
            g[a[i]].push_back({b[i],0});
            g[b[i]].push_back({a[i],0});
        }
    }
    mn[1]=mx[1]=0;
    dfs(1);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            d[i][j]=1000000001;
        }
    }
    for (int i=1;i<=n;i++) d[i][i]=0;
    for (int i=1;i<=m;i++){
        if (c[i]){
            d[a[i]][b[i]]=min(d[a[i]][b[i]],1);
            d[b[i]][a[i]]=min(d[b[i]][a[i]],-1);
        } else {
            d[a[i]][b[i]]=min(d[a[i]][b[i]],1);
            d[b[i]][a[i]]=min(d[b[i]][a[i]],1);
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            for (int t=1;t<=n;t++){
                d[j][t]=min(d[j][t],d[j][i]+d[i][t]);
            }
        }
    }
    int a=0;
    int mx=-1;
    for (int i=1;i<=n;i++){
        int cur=0;
        for (int j=1;j<=n;j++) cur=max(cur,d[i][j]);
        if (cur>mx){
            mx=cur;
            a=i;
        }
    }
    for (int i=1;i<=n;i++) ans[i]=d[a][i];
    cout<<"YES\n";
    cout<<mx<<endl;
    for (int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}