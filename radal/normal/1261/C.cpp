#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O3")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 1e6+10,mod = 1e9+7,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    } 
    return z; 
}
int n,m;
pll ja[8];
string s[N];
vector<vector<int> > d,d2;
bool isval(int x,int y){
    if (min(x,y) < 0 || x >= n || y >= m) return 0;
    return 1;
}
void bfs1(){
    rep(i,0,n){
        rep(j,0,m){
            d[i][j] = inf;
        }
    }
    queue<pll> q;
    rep(i,0,n){
        rep(j,0,m){
            if (s[i][j] == '.'){
                d[i][j] = 0;
                q.push({i,j});
            }
        }
    }
    while (!q.empty()){
        pll p = q.front();
        int x = p.X,y = p.Y;
        q.pop();
        rep(i,0,8){
            if (isval(x+ja[i].X,y+ja[i].Y) && d[x+ja[i].X][y+ja[i].Y] > d[x][y]+1){
                d[x+ja[i].X][y+ja[i].Y] = d[x][y]+1;
                q.push({x+ja[i].X,y+ja[i].Y});
            }
        }
    }
}
void bfs2(int t){
    queue<pll> q;
    rep(i,0,n){
        rep(j,0,m){
            if (d[i][j] > t){
                d2[i][j] = 0;
                q.push({i,j});
            }
            else d2[i][j] = inf;
        }
    }
    while (!q.empty()){
        pll p = q.front();
        int x = p.X,y = p.Y;
        q.pop();
        rep(i,0,8){
            if (isval(x+ja[i].X,y+ja[i].Y) && d2[x+ja[i].X][y+ja[i].Y] > d2[x][y]+1){
                d2[x+ja[i].X][y+ja[i].Y] = d2[x][y]+1;
                q.push({x+ja[i].X,y+ja[i].Y});
            }
        }
    }
}
bool check(int t){
    rep(i,0,n){
        rep(j,0,m){
            if (s[i][j] == 'X' && d2[i][j] > t) return 0;
        }
    }
    return 1;
}
int bs(){
    int l = 0,r = n+m+2,mid;
    while (r-l > 1){
        mid = (l+r) >> 1;
        bfs2(mid);
        if (check(mid)) l = mid;
        else r = mid;
    }
    return l;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    m += 2;
    s[0].resize(m);
    rep(i,0,m) s[0][i] = '.';
    rep(i,1,1+n){
        cin >> s[i];
        s[i] += '.';
        s[i] = '.'+s[i];
    }
    s[n+1] = s[0];
    n += 2;
    d.resize(n);
    d2.resize(n);
    rep(i,0,n){
        d[i].resize(m);
        d2[i].resize(m);
    }
    ja[0] = {1,0};
    ja[1] = {-1,0};
    ja[2] = {0,1};
    ja[3] = {0,-1};
    ja[4] = {1,1};
    ja[5] = {-1,-1};
    ja[6] = {1,-1};
    ja[7] = {-1,1};
    bfs1();
    int t = bs();
    cout << t << endl;
    n--;
    m--;
    rep(i,1,n){
        rep(j,1,m){
            if (d[i][j] > t) cout << 'X';
            else cout << '.';
        }
        cout << endl;
    }
    return 0;
}