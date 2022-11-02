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
constexpr int N = 1e5+20,mod = 1e9+7,inf = 1e9+10;
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

int n,m,q;
pll seg[N*4][12];
string c[N];

void rlx(int l,int i,int v){
    if (seg[v][i] != make_pair(-2,-2)) return;
    if (c[l][i] == '^'){
        seg[v][i] = {l-1,i};
        return;
    }
    if (i == 1 && c[l][i] == '<'){
        seg[v][i] = {l,0};
        return;
    }
    if (c[l][i] == '<' && c[l][i-1] == '>'){
        seg[v][i] = {-1,-1};
        return;
    }
    if (c[l][i] == '<'){
        rlx(l,i-1,v);
        seg[v][i] = seg[v][i-1];
        return;
    }
    if (i == m && c[l][i] == '>'){
        seg[v][i] = {l,i+1};
        return;
    }
    if (c[l][i] == '>' && c[l][i+1] == '<'){
        seg[v][i] = {-1,-1};
        return;
    }
    rlx(l,i+1,v);
    seg[v][i] = seg[v][i+1];
}

void build(int l,int r,int v = 1){
    if (r-l == 1){
        rep(i,0,m+1) seg[v][i] = {-2,-2};
        rep(i,1,m+1) rlx(l,i,v);
        return;
    }
    int mid = (l+r) >> 1,u = (v << 1);
    build(l,mid,u);
    build(mid,r,u|1);
    rep(i,1,m+1){
        if (seg[u|1][i].X == mid-1){
            seg[v][i] = seg[u][seg[u|1][i].Y];
        }
        else{
            seg[v][i] = seg[u|1][i];
        }
    }
}

void upd(int l,int r,int p,int v = 1){
    if (r-l == 1){
        rep(i,0,m+1) seg[v][i] = {-2,-2};
        rep(i,1,m+1) rlx(l,i,v);
        return;
    }
    int mid = (l+r) >> 1,u = (v << 1);
    if (p < mid) upd(l,mid,p,u);
    else upd(mid,r,p,u|1);
    rep(i,1,m+1){
        if (seg[u|1][i].X == mid-1){
            seg[v][i] = seg[u][seg[u|1][i].Y];
        }
        else{
            seg[v][i] = seg[u|1][i];
        }
    }
}

pll que(int l,int r,int s,int e,int i,int v = 1){
    if (s == l && r == e){
        return seg[v][i];
    }
    int mid = (l+r) >> 1,u = (v << 1);
    if (e <= mid) return que(l,mid,s,e,i,u);
    if (s >= mid) return que(mid,r,s,e,i,u|1);
    pll p = que(mid,r,mid,e,i,u|1);
    if (p.X != mid-1) return p;
    return que(l,mid,s,mid,p.Y,u);
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> q;
    rep(i,1,n+1){
        cin >> c[i];
        c[i] = '$'+c[i];
    }
    build(1,n+1,1);
    while (q--){
        char t;
        int x,y;
        cin >> t >> x >> y;
        if (t == 'C'){
            char s;
            cin >> s;
            c[x][y] = s;
            upd(1,n+1,x,1);
            continue;
        }
        pll p = que(1,n+1,1,x+1,y);
        cout << p.X << ' ' << p.Y << endl;
    }
    return 0;
}