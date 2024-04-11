#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=1e3+20,mod = 1e9+7,inf=2e8;
const long double eps = 0.0001;
int n,m;
string s[N];
int dist[N][N];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool isval(int x,int y){
    return (x >= 0 && y >= 0 && y < m && x < n && s[x][y] != 'T');
}
void bfs(int x,int y){
    dist[x][y] = 1;
    queue <pll> q;
    q.push({x,y});
    while (!q.empty()){
        pll p = q.front();
        q.pop();
        rep(i,0,4){
            int j = p.X+dx[i],k = p.Y+dy[i];
            if (isval(j,k) && !dist[j][k]){
                q.push({j,k});
                dist[j][k] = dist[p.X][p.Y]+1;
            }
        }
    }
    return;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int x,y,x2,y2;
    rep(i,0,n){
        cin >> s[i];
        rep(j,0,m){
            if (s[i][j] == 'E'){
                x = i;
                y = j;
            }
            if (s[i][j] == 'S'){
                x2 = i;
                y2 = j;
            }
        }   
    }
    bfs(x,y);
    if (!dist[x2][y2]){
        cout << -1;
        return 0;
    }
    ll ans = 0;
    rep(i,0,n){
        rep(j,0,m){
            if (s[i][j] != 'T' && s[i][j] != 'S' && s[i][j] != 'E'){
                if (dist[i][j] != 0 && dist[i][j] <= dist[x2][y2]){
                    ans += int(s[i][j])-int('0');
                }
            }
        }
    }
    cout << ans;
    return 0;
}