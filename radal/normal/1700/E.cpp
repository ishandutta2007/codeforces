#include <bits/stdc++.h>
#pragma GCC target("sse,sse2")
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
constexpr int N = 5e5+20,mod = 1e9+7,inf = 1e9+10,sq = 340;
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
        k /= 2;
    } 
    return z; 
}
vector<vector<int> > a;
vector<pll> bad;
int n,m;
bool check(int i,int j){
    if (min(i,j) < 0 || i >= n || j >= m) return 0;
    if (a[i][j] == 1) return 1;
    if (i && a[i][j] > a[i-1][j]) return 1;
    if (j && a[i][j] > a[i][j-1]) return 1;
    if (i < n-1 && a[i][j] > a[i+1][j]) return 1;
    if (j < m-1 && a[i][j] > a[i][j+1]) return 1;
    return 0;
}
bool good(int x,int y,int i,int j){
    bool f = 1;
    for (pll p : bad) if (!check(p.X,p.Y)){
        f = 0;
        return 0;
    }
    f &= check(x,y);
    f &= check(i,j);
    if (x) f &= check(x-1,y);
    if (y) f &= check(x,y-1);
    if (x < n-1) f &= check(x+1,y);
    if (y < m-1) f &= check(x,y+1);
    if (i) f &= check(i-1,j);
    if (j) f &= check(i,j-1);
    if (i < n-1) f &= check(i+1,j);
    if (j < m-1) f &= check(i,j+1);
    return f;
}
int br(int x,int y){
    int ans = 0;
    rep(i,0,n){
        rep(j,0,m){
            swap(a[x][y],a[i][j]);
            bool f = good(x,y,i,j);
            swap(a[x][y],a[i][j]);
            ans += f;
        }
    }
    return ans;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    a.resize(n);
    rep(i,0,n){
        a[i].resize(m);
        rep(j,0,m)
            cin >> a[i][j];
    }
    rep(i,0,n){
        rep(j,0,m){
            if (!check(i,j)) bad.pb({i,j});
        }
    }
    if (bad.empty()){
        cout << 0;
        return 0;
    }
    int x = bad[0].X,y = bad[0].Y;
    int ans = br(x,y);
    if (x){
        ans += br(x-1,y);
        swap(a[x][y],a[x-1][y]);
        ans -= good(x,y,x-1,y);
        swap(a[x][y],a[x-1][y]);
    }
    if (x < n-1){
        ans += br(x+1,y);
        swap(a[x][y],a[x+1][y]);
        ans -= good(x,y,x+1,y);
        swap(a[x][y],a[x+1][y]);
    }
    if (y){
        ans += br(x,y-1);
        swap(a[x][y],a[x][y-1]);
        ans -= good(x,y,x,y-1);
        swap(a[x][y],a[x][y-1]);
    }
    if (y < m-1){
        ans += br(x,y+1);
        swap(a[x][y],a[x][y+1]);
        ans -= good(x,y,x,y+1);
        swap(a[x][y],a[x][y+1]);
    }
    if (ans) cout << 1 << ' ' << ans << endl;
    else cout << 2;
    return 0;
}