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
const int N = 2e5+20,mod = 1e9+7,inf = 2e9,sq = 400;
int poww(int n,ll k){
    if (!k) return 1;
    if (k == 1) return n;
    int r = poww(n,k/2);
    return 1ll*r*r%mod*poww(n,k&1)%mod;
}
inline int mkay(int x,int y){
    if (x+y < mod) return x+y;
    return x+y-mod;
}
int seg[4*N][10][10],lz[N*4],seg2[4*N][2],ind[20];
string s;
int n,k;
void build(int l,int r,int v){
    if (r-l == 1){
        seg2[v][0] = s[l]-'a';
        seg2[v][1] = s[l]-'a';
        lz[v] = -1;
        return;
    }
    lz[v] = -1;
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
    rep(i,0,k) rep(j,0,k) seg[v][i][j] = seg[u][i][j]+seg[u|1][i][j];
    seg[v][seg2[u][1]][seg2[u|1][0]]++;
    seg2[v][0] = seg2[u][0];
    seg2[v][1] = seg2[u|1][1];
}
void upd(int l,int r,int s,int e,int x,int v){
    if (l >= e || s >= r) return;
    if (l >= s && e >= r){
        lz[v] = x;
        seg2[v][1] = seg2[v][0] = x;
        rep(i,0,k) rep(j,0,k) seg[v][i][j] = 0;
        seg[v][x][x] = r-l-1;
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    if (lz[v] != -1){
        lz[u] = lz[u|1] = lz[v];
        rep(i,0,k){
            rep(j,0,k){
                seg[u][i][j] = 0;
                seg[u|1][i][j] = 0;
            }
        }
        seg[u][lz[v]][lz[v]] = m-l-1;
        seg[u|1][lz[v]][lz[v]] = r-m-1;
        seg2[u][0] = seg2[u][1] = seg2[u|1][0] = seg2[u|1][1] = lz[v];
        lz[v] = -1;
    }
    upd(l,m,s,e,x,u);
    upd(m,r,s,e,x,u|1);
    seg2[v][0] = seg2[u][0];
    seg2[v][1] = seg2[u|1][1];
    rep(i,0,k){
        rep(j,0,k){
            seg[v][i][j] = seg[u][i][j]+seg[u|1][i][j];
        }
    }
    seg[v][seg2[u][1]][seg2[u|1][0]]++;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int m;
    cin >> n >> m >> k >> s;
    build(0,n,1);
    while (m--){
        int t;
        cin >> t;
        if (t == 2){
            string r;
            cin >> r;
            rep(i,0,k) ind[r[i]-'a'] = i;
            int ans = 1;
            rep(i,0,k) rep(j,0,k) if (ind[j] <= ind[i]) ans += seg[1][i][j];
            cout << ans << endl;
        }
        else{
            int l,r;
            char c;
            cin >> l >> r >> c;
            l--;
            upd(0,n,l,r,c-'a',1);
        }
    }
}