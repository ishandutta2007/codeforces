#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;
typedef pair<int,int> pll;
const long long int N=1e3+30,inf = 1e9;
string s[N];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

vector <pll> s1,s2,s3;
int dist[N][N];
ll di[3][N][N];
int n,m;
bool isval(int x,int y){
    return (x >= 0 && y >= 0 && x < n && y < m && s[x][y] != '#');
}
int bfs(vector <pll> a,char b){
    memset(dist,0,sizeof dist);
    deque <pll> q;
    for (pll u : a){
        q.pb(u);
        dist[u.X][u.Y] = 1;
    }
    while (!q.empty()){
        pll v = q.front();
        q.pop_front();
        rep(i,0,4){
            int x = v.X+dx[i];
            int y = v.Y+dy[i];
            if (!isval(x,y)) continue;
            if (!dist[x][y] && s[x][y] == '.'){
                q.pb({x,y});
                dist[x][y] = dist[v.X][v.Y]+1;
                continue;
            }
            if (!dist[x][y]){
                q.push_front({x,y});
                dist[x][y] = dist[v.X][v.Y];
                continue;
            }
            if (s[x][y] == '.' && dist[x][y] > dist[v.X][v.Y]+1){
                q.pb({x,y});
                dist[x][y] = dist[v.X][v.Y]+1;
                continue;
            }
            if (s[x][y] != '.' && dist[x][y] > dist[v.X][v.Y]){
                q.push_front({x,y});
                dist[x][y] = dist[v.X][v.Y];
            }
        }
    }
    int ans = inf;
    rep(i,0,n){
        rep(j,0,m){
            if (s[i][j] == b){
                if (dist[i][j]) ans = min(ans,dist[i][j]-1);
            }
        }
    }
    return ans;
}
void bfs2(vector<pll> sc,int num){
    deque <pll> q;
    for (pll u : sc){
        q.pb(u);
        di[num][u.X][u.Y] = 1;
    }
    while (!q.empty()){
        pll v = q.front();
        q.pop_front();
        rep(i,0,4){
            int x = v.X+dx[i];
            int y = v.Y+dy[i];
            if (!isval(x,y)) continue;
            if (!di[num][x][y] && s[x][y] == '.'){
                q.pb({x,y});
                di[num][x][y] = di[num][v.X][v.Y]+1;
                continue;
            }
            if (!di[num][x][y]){
                q.push_front({x,y});
                di[num][x][y] = di[num][v.X][v.Y];
                continue;
            }
            if (s[x][y] == '.' && di[num][x][y] > di[num][v.X][v.Y]+1){
                q.pb({x,y});
                di[num][x][y] = di[num][v.X][v.Y]+1;
                continue;
            }
            if (s[x][y] != '.' && di[num][x][y] > di[num][v.X][v.Y]){
                q.push_front({x,y});
                di[num][x][y] = di[num][v.X][v.Y];
            }
        }
    }
    return;
}
int main(){
	ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    cin >> n >> m;
    rep(i,0,n){
        cin >> s[i];
        rep(j,0,m){
            if (s[i][j] == '1') s1.pb({i,j});
            if (s[i][j] == '2') s2.pb({i,j});
            if (s[i][j] == '3') s3.pb({i,j});
        }
    }
    ll ans = min(bfs(s1,'3')+bfs(s1,'2'),min(bfs(s2,'1')+bfs(s2,'3'),bfs(s3,'1')+bfs(s3,'2')));
    bfs2(s1,0);
    bfs2(s2,1);
    bfs2(s3,2);
    rep(i,0,n){
        rep(j,0,m){
            if (s[i][j] == '.' && min(di[0][i][j],min(di[1][i][j],di[2][i][j]))){
                ans = min(ans,di[0][i][j]+di[1][i][j]+di[2][i][j]-5);
            }
        }
    }
    if (ans < inf) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}