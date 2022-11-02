#include <bits/stdc++.h>
#pragma GCC optimize("O2")
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
typedef pair<int,int> pll;
const int N = 1e3+20,mod = 1e9+7,inf = 2e9,sq = 400;
int poww(int n,ll k){
    if (!k) return 1;
    if (k == 1) return n;
    int r = poww(n,k/2);
    return 1ll*r*r%mod*poww(n,k&1)%mod;
}
bitset<N> b[N];
string s[N];
int m,n,t;
int ti[N][N];
void bfs(){
    queue<pll> q;
    rep(i,0,n) rep(j,0,m) if (!ti[i][j]) q.push({i,j});
    while (!q.empty()){
        pll p = q.front();
        int x = p.X,y = p.Y;
        q.pop();
        if(x && ti[x-1][y] > ti[x][y]+1){
            ti[x-1][y] = ti[x][y]+1;
            q.push({x-1,y});
        }
        if (x < n-1 && ti[x+1][y] > ti[x][y]+1){
            ti[x+1][y] = ti[x][y]+1;
            q.push({x+1,y});
        }
        if(y && ti[x][y-1] > ti[x][y]+1){
            ti[x][y-1] = ti[x][y]+1;
            q.push({x,y-1});
        }
        if (y < m-1 && ti[x][y+1] > ti[x][y]+1){
            ti[x][y+1] = ti[x][y]+1;
            q.push({x,y+1});
        }
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(ti,63,sizeof ti);
    cin >> n >> m >> t;
    rep(i,0,n){
        cin >> s[i];
        rep(j,0,m) b[i][j] = s[i][j]-'0';
    }
    bool fl = 0;
    rep(i,0,n){
        rep(j,0,m){
            if (i < n-1 && b[i][j] == b[i+1][j]){
                ti[i][j] = 0;
                ti[i+1][j] = 0;
                fl = 1;
            }
            if (j < m-1 && b[i][j] == b[i][j+1]){
                ti[i][j] = 0;
                ti[i][j+1] = 0;
                fl = 1;
            }
        }
    }
    if (!fl){
        while (t--){
            int i,j;
            ll p;
            cin >> i >> j >> p;
            cout << b[i-1][j-1] << endl;
        }
        return 0;
    }
    bfs();
    while (t--){
        int i,j;
        ll p;
        cin >> i >> j >> p;
        i--;
        j--;
        if (ti[i][j] >= p || ((p-ti[i][j])&1) == 0){
            cout << b[i][j] << endl;
            continue;
        }
        cout << 1-b[i][j] << endl;
    }
}