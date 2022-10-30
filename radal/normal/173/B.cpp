#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)

using namespace std;

typedef long long  int ll;
typedef pair<ll,ll> pll;

const long long int N=1e3+30,mod = 1e9+7,inf=1e18;
const long double eps = 0.0001;
int n,m;
int dist[N][N];
string a[N];
void bfs(){
    queue <pll> q;
    rep(j,0,m){
        dist[n-1][j] = 1;
        if (a[n-1][j] == '#') q.push({n-1,j});
    }
    while (!q.empty()){
        pll p = q.front();
        q.pop();
        rep(i,0,n-1){
            if (!dist[i][p.Y]){
                dist[i][p.Y] = dist[p.X][p.Y]+1;
                if (a[i][p.Y] == '#') q.push({i,p.Y});
            }
        }
        rep(j,0,m){
            if (!dist[p.X][j]){
                dist[p.X][j] = dist[p.X][p.Y]+1;
                if (a[p.X][j] == '#') q.push({p.X,j});
            }
        }
        if (p.X == 0 || p.Y == 0) break;
    }
    return;
}
int main(){
    ios :: sync_with_stdio(0); cout.tie(0); cin.tie(0);
    cin >> n >> m;
    m++;
    rep(i,0,n){
        cin >> a[i];
        a[i] = '.'+a[i];
    }
    bool f = 0,f1 = 0;
    rep(j,1,m){
        if (j > 1 && a[0][j] == '#'){
            f1 = 1;
            //break;
        }

        if (a[0][j] == '#'){ 
            f = 1;
            if (j > 1) break;
        }
    }
    if (!f){
        cout << -1;
        return 0;
    }
    if (!f1){
        rep(i,1,n){
            if (a[i][1] == '#') f1 = 1;
        }
        if (!f1){
            cout << -1;
            return 0;
        }
    }
    bfs();
    cout << dist[0][0]-1;
    return 0;
}