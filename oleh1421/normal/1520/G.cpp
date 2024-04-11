#include<bits/stdc++.h>
typedef long long ll;
//#define endl '\n'

using namespace std;
const int N=2010;
const int A=10000001;
const ll inf=1000000000000000001ll;
ll d[2][N][N];
int a[N][N];
ll n,m,w;
void bfs(int x,int y,int t){
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            d[t][i][j]=inf;
        }
    }
    d[t][x][y]=0;
    queue<pair<int,int> >q;
    q.push({x,y});
    while (!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for (int dx=-1;dx<=1;dx++){
            for (int dy=-1;dy<=1;dy++){
                if (dx && dy) continue;
                if (!dx && !dy) continue;
                if (x+dx>n || x+dx<1 || y+dy>m || y+dy<1 || d[t][x+dx][y+dy]<inf || a[x+dx][y+dy]==-1) continue;
                d[t][x+dx][y+dy]=d[t][x][y]+w;
                q.push({x+dx,y+dy});
            }
        }
    }
}
void solve(){
    cin>>n>>m>>w;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    bfs(1,1,0);
    bfs(n,m,1);
    ll res=d[0][n][m];
    ll mn1=inf,mn2=inf;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i][j]){
                mn1=min(mn1,d[0][i][j]+a[i][j]);
                mn2=min(mn2,d[1][i][j]+a[i][j]);
            }
        }
    }
    res=min(res,mn1+mn2);
    if (res>=inf) res=-1;
    cout<<res<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/**
5 5 5
6 6 6 6 6
**/