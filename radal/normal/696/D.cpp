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
const long long int N = 2e2+20,mod = 1e9+7,inf = 1e18,sq = 400,sig = 26;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    return a+b;
}
struct matrix{
    int n,m;
    vector< vector<ll> > a;
    matrix (int n,int m) : n(n),m(m){
        a.resize(n);
        rep(i,0,n){
            a[i].resize(m);
            fill(a[i].begin(),a[i].end(),-inf);
        }
        return;
    }
    vector<ll>& operator[](int i){
        return a[i];
    }
    matrix operator *(const matrix &b){
        matrix c = matrix (n,b.m);
        rep(i,0,n)
            rep(j,0,b.m)
                rep(k,0,m)
                    c[i][j] = max(c[i][j],a[i][k]+b.a[k][j]);
        return c;
    }
    void print(){
        rep(i,0,n){
            rep(j,0,m) cout << a[i][j] << ' ';
            cout << endl;
        }
    }
};
int nxt[N][sig],sz,f[N],ind[N];
ll A[N],B[N];
vector<int> adj[N];
inline int add_trie(string s){
    int cur = 0;
    int n = s.size();
    rep(i,0,n){
        int c = s[i]-'a';
        if (nxt[cur][c]) cur = nxt[cur][c];
        else{
            sz++;
            nxt[cur][c] = sz;
            cur = sz;
        }
    }
    return cur;
}
inline void buildaho(){
    queue<int> q;
    rep(i,0,26)
        if (nxt[0][i])
            q.push(nxt[0][i]);
    while (!q.empty()){
        int v = q.front();
        adj[f[v]].pb(v);
        q.pop();
        A[v] += A[f[v]];
        rep(i,0,26){
            if (nxt[v][i]){
                f[nxt[v][i]] = nxt[f[v]][i];
                q.push(nxt[v][i]);
            }
            else nxt[v][i] = nxt[f[v]][i];
        }
    }
}
matrix powwmat(matrix a,ll k){
    matrix c = matrix(a.n,a.m);
    c.a[0][0] = 0;
    while(k){
        if (k&1) c = c * a;
        a = a * a;
        k /= 2;
    }
    return c;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    ll l;
    cin >> n >> l;
    rep(i,0,n) cin >> B[i];
    rep(i,0,n){
        string s;
        cin >> s;
        int vert = add_trie(s);
        A[vert] += B[i];
        ind[i] = vert;
    }
    buildaho();
    sz++;
    matrix a(sz,sz);
    rep(i,0,sz)
        rep(j,0,26)
            if (nxt[i][j] >= 0)
                a.a[i][nxt[i][j]] = A[nxt[i][j]];
    matrix c = powwmat(a,l);
    ll mx = 0; 
    rep(i,0,sz) mx = max(mx,c.a[0][i]);
    cout << mx;
}