#include "bits/stdc++.h"
using namespace std;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXM = 2e5+10, MAXL = 17, ALP = 26, MOD = 998244353, MAXK = 5e5+10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};


int n, dX, depth[MAXN], par[MAXN];
vector<int> adj[MAXN];

int qry1(int a){
    a++;
    cout << "d " << a << '\n'; cout.flush();
    string d; cin >> d; if (d == "-1" || d == "Wrong answer") exit(0);
    if (!stoi(d)){ cout << "! " << a << '\n'; cout.flush(); exit(0); }
    return stoi(d);
}
int qry2(int a){
    a++;
    cout << "s " << a << '\n'; cout.flush();
    string b; cin >> b; if (b == "-1" || b == "Wrong answer") exit(0);
    return stoi(b)-1;
}
bool isAnc(int a){
    return qry1(a)+depth[a]==dX;
}
void dfs1(int c=0, int p=-1, int d=0){
    depth[c] = d; par[c] = p;
    for (auto nxt : adj[c]) if (nxt != p) dfs1(nxt, c, d+1);
}
bool blocked[MAXN];
int sub[MAXN];
int dfsSub(int c, int p){
    sub[c]=1;
    for (auto nxt : adj[c]) if (nxt != p && !blocked[nxt]) sub[c] += dfsSub(nxt, c);
    return sub[c];
}
int dfsCent(int c, int p, int cn){
    for (auto nxt : adj[c]) if (nxt != p && !blocked[nxt] && sub[nxt] > cn/2) return dfsCent(nxt, c, cn);
    return c;
}
void dfsAns(int c=0){
    int cn = dfsSub(c, -1), cc = dfsCent(c, -1, cn);
    blocked[cc] = 1; int nxt=-1;
    if (isAnc(cc)) nxt = qry2(cc);
    else nxt = par[cc];
    assert(!blocked[nxt]);
    dfsAns(nxt);
}
void solve(){
    cin >> n;
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    dX = qry1(0); dfs1();
    memset(blocked, 0, sizeof(blocked)); dfsAns();
    assert(false);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t;
    while (t--) solve();
}