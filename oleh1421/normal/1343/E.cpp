#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300020;
ll p[N];
vector<int>g[N];
int d[3][N];
int n,m,a,b,c;
void bfs(int s,int j){
    for (int i=1;i<=n;i++){
        d[j][i]=-1;
    }
    d[j][s]=0;
    queue<int>q;
    q.push(s);
    while (!q.empty()){
        int v=q.front();
        q.pop();

        for (auto to:g[v]){
            if (d[j][to]==-1){
                d[j][to]=d[j][v]+1;
                q.push(to);
            }
        }
    }
}
void solve(){
    cin>>n>>m>>a>>b>>c;
    for (int i=1;i<=m;i++) cin>>p[i];
    sort(p+1,p+m+1);
    for (int i=1;i<=m;i++){
        p[i]+=p[i-1];
    }
    for (int i=1;i<=n;i++){
        g[i].clear();
    }
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bfs(a,0);
    bfs(b,1);
    bfs(c,2);
    ll res=1000000000000000001ll;
    for (int i=1;i<=n;i++){
        int x=d[0][i];
        int y=d[1][i];
        int z=d[2][i];
//        cout<<i<<" "<<x<<" "<<y<<" "<<z<<endl;
        if (x+y+z>m) continue;
        res=min(res,p[x+y+z]+p[y]);
    }
    cout<<res<<endl;

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
/*
1
4 3 2 3 4
1 2 3
1 2
1 3
1 4
*/