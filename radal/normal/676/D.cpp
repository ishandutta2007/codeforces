#include <bits/stdc++.h>
#pragma GCC optimize("O3,no-stack-protector,unroll-loops")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
typedef pair<long double,long double> pld;
const long long int N = 1e3+10,mod = 1e9+7,inf = 1e9,sq = 600,maxm = 2e5+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int n,m;
int d[N][N][4];
string s[N];
inline bool isval(int x,int y,int x2,int y2,int t){
    if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) return 0;
    if (s[x][y] == '*' || s[x2][y2] == '*') return 0;
    if (x-x2 == 1){
        if ((s[x][y] == '|' && (t&1)) || ((s[x][y] == '-') && (t&1) == 0)) return 0;
        if ((s[x][y] == '^' && t) || (s[x][y] == '>' && t != 3) || (s[x][y] == 'v' && t != 2) || (s[x][y] == '<' && t != 1)) return 0;
        if ((s[x][y] == 'L' && t == 1) || (s[x][y] == 'U' && !t) || (s[x][y] == 'R' && t == 3) || (s[x][y] == 'D' && t == 2)) return 0;
        if ((s[x2][y2] == '|' && (t&1)) || ((s[x2][y2] == '-') && (t&1) == 0)) return 0;
        if ((s[x2][y2] == '^' && t != 2) || (s[x2][y2] == '>' && t != 1) || (s[x2][y2] == 'v' && t) || (s[x2][y2] == '<' && t != 3)) return 0;
        if ((s[x2][y2] == 'L' && t == 3) || (s[x2][y2] == 'U' && t == 2) || (s[x2][y2] == 'R' && t == 1) || (s[x2][y2] == 'D' && !t)) return 0;
        return 1;
    }
    if (x-x2 == -1){
        if ((s[x][y] == '|' && (t&1)) || ((s[x][y] == '-') && (t&1) == 0)) return 0;
        if ((s[x2][y2] == '^' && t) || (s[x2][y2] == '>' && t != 3) || (s[x2][y2] == 'v' && t != 2) || (s[x2][y2] == '<' && t != 1)) return 0;
        if ((s[x2][y2] == 'L' && t == 1) || (s[x2][y2] == 'U' && !t) || (s[x2][y2] == 'R' && t == 3) || (s[x2][y2] == 'D' && t == 2)) return 0;
        if ((s[x2][y2] == '|' && (t&1)) || ((s[x2][y2] == '-') && (t&1) == 0)) return 0;
        if ((s[x][y] == '^' && t != 2) || (s[x][y] == '>' && t != 1) || (s[x][y] == 'v' && t) || (s[x][y] == '<' && t != 3)) return 0;
        if ((s[x][y] == 'L' && t == 3) || (s[x][y] == 'U' && t == 2) || (s[x][y] == 'R' && t == 1) || (s[x][y] == 'D' && !t)) return 0;
        return 1;
    }
    if (y-y2 == 1){
        if ((s[x][y] == '|' && (t&1) == 0) || ((s[x][y] == '-') && (t&1))) return 0;
        if ((s[x][y] == '^' && t != 3) || (s[x][y] == '>' && t != 2) || (s[x][y] == 'v' && t != 1) || (s[x][y] == '<' && t)) return 0;
        if ((s[x][y] == 'L' && !t) || (s[x][y] == 'D' && t == 1) || (s[x][y] == 'R' && t == 2) || (s[x][y] == 'U' && t == 3)) return 0;
        if ((s[x2][y2] == '|' && (t&1) == 0) || ((s[x2][y2] == '-') && (t&1))) return 0;
        if ((s[x2][y2] == '^' && t != 1) || (s[x2][y2] == '>' && t) || (s[x2][y2] == 'v' && t != 3) || (s[x2][y2] == '<' && t != 2)) return 0;
        if ((s[x2][y2] == 'L' && t == 2) || (s[x2][y2] == 'D' && t == 3) || (s[x2][y2] == 'R' && !t) || (s[x2][y2] == 'U' && t == 1)) return 0;
        return 1;
    }
    swap(x,x2);
    swap(y,y2);
    if ((s[x][y] == '|' && (t&1) == 0) || ((s[x][y] == '-') && (t&1))) return 0;
    if ((s[x][y] == '^' && t != 3) || (s[x][y] == '>' && t != 2) || (s[x][y] == 'v' && t != 1) || (s[x][y] == '<' && t)) return 0;
    if ((s[x][y] == 'L' && !t) || (s[x][y] == 'D' && t == 1) || (s[x][y] == 'R' && t == 2) || (s[x][y] == 'U' && t == 3)) return 0;
    if ((s[x2][y2] == '|' && (t&1) == 0) || ((s[x2][y2] == '-') && (t&1))) return 0;
    if ((s[x2][y2] == '^' && t != 1) || (s[x2][y2] == '>' && t) || (s[x2][y2] == 'v' && t != 3) || (s[x2][y2] == '<' && t != 2)) return 0;
    if ((s[x2][y2] == 'L' && t == 2) || (s[x2][y2] == 'D' && t == 3) || (s[x2][y2] == 'R' && !t) || (s[x2][y2] == 'U' && t == 1)) return 0;
    return 1;
}
inline void bfs(int u,int v){
    d[u][v][0] = 0;
    queue<pair<pll,int>> q;
    q.push({{u,v},0});
    while (!q.empty()){
        auto p = q.front();
        int x = p.X.X,y = p.X.Y,t = p.Y;
        q.pop();
        if (isval(x,y,x+1,y,t) && d[x][y][t]+1 < d[x+1][y][t]){
            d[x+1][y][t] = d[x][y][t]+1;
            q.push({{x+1,y},t});
        }
        if (isval(x,y,x-1,y,t) && d[x][y][t]+1 < d[x-1][y][t]){
            d[x-1][y][t] = d[x][y][t]+1;
            q.push({{x-1,y},t});
        }
        if (isval(x,y,x,y+1,t) && d[x][y][t]+1 < d[x][y+1][t]){
            d[x][y+1][t] = d[x][y][t]+1;
            q.push({{x,y+1},t});
        }
        if (isval(x,y,x,y-1,t) && d[x][y][t]+1 < d[x][y-1][t]){
            d[x][y-1][t] = d[x][y][t]+1;
            q.push({{x,y-1},t});
        }
        int t2 = t+1;
        if (t2 == 4) t2 = 0;
        if (d[x][y][t2] > d[x][y][t]+1){
            d[x][y][t2] = d[x][y][t]+1;
            q.push({{x,y},t2});
        }
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);cout.tie(0);
    memset(d,63,sizeof d);
    cin >> n >> m;
    rep(i,0,n) cin >> s[i];
    int x,y;
    cin >> x >> y;
    x--;
    y--;
    bfs(x,y);
    int u,v;
    cin >> u >> v;
    u--;
    v--;
    int D = inf;
    rep(i,0,4) D = min(D,d[u][v][i]);
    if (D == inf) cout << -1;
    else cout << D << endl;
    return 0;
}