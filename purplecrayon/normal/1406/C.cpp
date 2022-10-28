#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXM = 1e2+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, sub[MAXN], vals[MAXN];
vector<int> adj[MAXN];

int dfs(int c=0, int p=-1){
    sub[c]=1; int cmx = 0;
    for (auto nxt : adj[c]) if (nxt != p) {
        int v = dfs(nxt, c);
        sub[c] += v, cmx = max(cmx, v);
    }
    cmx = max(cmx, n-sub[c]);
    vals[c] = cmx;
    return sub[c];
}
void solve(){
    cin >> n; for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    dfs();
    int mn = *min_element(vals, vals+n);
    vector<int> cent;
    for (int i = 0; i < n; i++){
        if (vals[i] == mn) cent.push_back(i);
    }
    if (sz(cent)==1){
       for (int rep = 0; rep < 2; rep++) cout << (0+1) << ' ' << (1+adj[0].back()) << '\n'; 
       return;
    }
    for (auto nxt : adj[cent[0]]) if (nxt != cent[1]) {
        cout << (cent[0]+1) << ' ' << (nxt+1) << '\n';
        cout << (cent[1]+1) << ' ' << (nxt+1) << '\n';
        return;
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}