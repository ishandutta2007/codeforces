//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
bool start[1200001];
vector<int> g[1200001];
vector<int>startV;
int cnt=0;
vector<int> bfs(vector<int>s){
    vector<int>d(cnt+1,-1);
    queue<int>q;
    for (auto i:s) q.push(i),d[i]=0;
    while (!q.empty()){
        int v=q.front();
        q.pop();
        for (auto to:g[v]){
            if (d[to]==-1){
                d[to]=d[v]+1;
                q.push(to);
            }
        }
    }
    return d;
}
bool ok(int T){
    vector<int>d=bfs(startV);
    vector<int>s;
    for (int i=1;i<=cnt;i++){
        if (d[i]>=T) s.push_back(i);
    }
    vector<int>d1=bfs(s);
    for (auto i:startV){
        if (d1[i]>T || d1[i]==-1) return false;
    }
    return true;
}
bool used[1000011];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    vector<vector<int> >a;
    a.resize(n+1);
    for (int i=0;i<=n;i++) a[i].resize(m+1);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;cin>>c;
            if (c=='X') a[i][j]=++cnt;
            else a[i][j]=0;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (!a[i][j]) continue;
            for (int dx=-1;dx<=1;dx++){
                for (int dy=-1;dy<=1;dy++){
                    if (!dx && !dy) continue;
                    if (i+dx>=1 && j+dy>=1 && i+dx<=n && j+dy<=m && a[i+dx][j+dy]) g[a[i][j]].push_back(a[i+dx][j+dy]);
                    else start[a[i][j]]=true;
                }
            }
        }
    }
    for (int i=1;i<=cnt;i++){
        if (start[i]) startV.push_back(i);
    }
    int l=0;
    int r=1000001;
    while (r-l>1){
        int m=(l+r)/2;
        if (ok(m)) l=m;
        else r=m;
       // cout<<m<<" "<<ok(m)<<endl;
    }
    int T=l;
    cout<<T<<endl;
    vector<int>d=bfs(startV);
    for (int i=1;i<=cnt;i++){
        if (d[i]>=T) used[i]=true;
      //  cout<<i<<" "<<d[i]<<endl;
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (used[a[i][j]]) cout<<'X';
            else cout<<'.';
        }
        cout<<endl;
    }
    return 0;
}