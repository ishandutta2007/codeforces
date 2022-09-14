//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=610;
const ll mod=998244353;
int dist[N][N],f[N][N];
int n,m;
vector<int>g[N];
int cnt[N];

ll bfs(int s){
    for (int i=1;i<=n;i++) dist[s][i]=-1,cnt[i]=0;
    dist[s][s]=0;
    queue<int>q;
    q.push(s);
    ll res=1ll;
    while (!q.empty()){
        int v=q.front();
        q.pop();
        res*=cnt[v]*1ll;
        res%=mod;
        for (int to:g[v]){
            if (dist[s][to]==-1 || dist[s][to]==dist[s][v]+1){
                dist[s][to]=dist[s][v]+1;
                if (!cnt[to]) q.push(to);
                cnt[to]++;
            }
        }
    }
    return res;
}

int get(int s,int t){
    int cnt=0;
    for (int i=1;i<=n;i++){
        if (dist[s][i]+dist[i][t]==dist[s][t]) cnt++;
    }
    if (cnt!=dist[s][t]+1) return 0;
    ll res=1ll;
    for (int i=1;i<=n;i++){
        if (dist[s][i]+dist[i][t]==dist[s][t]) continue;
        int cnt=0;
        for (int p:g[i]){
            if (dist[s][p]+1==dist[s][i] && dist[t][p]+1==dist[t][i]) cnt++;
        }
        res*=cnt*1ll;
        res%=mod;
    }
    return res;

}
void solve(){
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i=1;i<=n;i++){
        f[i][i]=bfs(i);
    }
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            f[i][j]=f[j][i]=get(i,j);
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/*
4
1 2 2 2
*/