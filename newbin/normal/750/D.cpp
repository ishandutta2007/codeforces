#include<bits/stdc++.h>
using namespace std;
const int maxn = 350;
int a[maxn][maxn];
int dx[8] = {0,-1,-1,-1,0,1,1,1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int vis[maxn][maxn][8][31];
struct node{int x, y, dir, step;};
int d[50];
int n;
queue<node> q;
int main()
{
    cin>>n;
    for(int i = 0; i < n; ++i) scanf("%d", &d[i]);
    d[0]--;
    q.push((node){175,175, 2, 0});
    vis[175][175][2][0] = 1;
    while(q.size()){
        node t = q.front(); q.pop();
        int x = t.x, y = t.y, dir = t.dir;
        int p = d[t.step];
        for(int i = 0; i <= p; ++i){
            int xx = x + dx[dir]*i;
            int yy = y + dy[dir]*i;
            a[xx][yy] = 1;
        }
        x = x + dx[dir]*p;
        y = y + dy[dir]*p;
        if(t.step+1 < n && !vis[x][y][(dir+7)%8][t.step+1]){
            vis[x][y][(dir+7)%8][t.step+1] = 1;
            q.push((node){x,y,(dir+7)%8,t.step+1});
        }
        if(t.step+1 < n && !vis[x][y][(dir+1)%8][t.step+1]){
            vis[x][y][(dir+1)%8][t.step+1] = 1;
            q.push((node){x,y,(dir+1)%8,t.step+1});
        }
    }
    int ans = 0;
    for(int i = 0; i < maxn; ++i) for(int j = 0; j < maxn; ++j) if(a[i][j]) ans++;
    cout<<ans<<endl;
}