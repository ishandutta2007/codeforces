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
const int MAXN = 2.5e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 20, MOD = 998244353, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, m, k, depth[MAXN], par[MAXN];
vector<int> adj[MAXN], ch[MAXN], back[MAXN];
bool vis[MAXN];

void dfs(int c=0, int p=-1, int d=0){
    depth[c]=d; vis[c]=1; par[c]=p;
    for (auto nxt : adj[c]) if (nxt != p) {
        if (vis[nxt]) { if (depth[c] > depth[nxt]) back[c].push_back(nxt); }
        else {
            ch[c].push_back(nxt); dfs(nxt, c, d+1);
        }
    }
}
void solve(){
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    memset(vis, 0, sizeof(vis)); dfs();
    
    /*for (int i = 0; i < n; i++){
        cerr << i << ":\n";
        cerr << "DEPTH: " << depth[i] << '\n';
        cerr << "PAR: " << par[i] << '\n';
        cerr << "BACK: ";
        for (auto& it : back[i]) cerr << it << ' ';
        cerr << '\n';
        cerr << "CHILDREN: ";
        for (auto& it : ch[i]) cerr << it << ' ';
        cerr << '\n';
    }*/

    vector<int> lv;
    for (int i = 0; i < n; i++) if (!sz(ch[i])) lv.push_back(i);
    sort(lv.begin(), lv.end(), [&](auto a, auto b) {
        return depth[a] < depth[b];
    });
    if (depth[lv.back()]+1 >= n/k){
        cout << "PATH\n" << depth[lv.back()]+1 << '\n';
        int c=lv.back();
        while (c != -1){
            cout << c+1 << ' ';
            c = par[c];
        }
        exit(0);
    }
    cout << "CYCLES\n";
    int pr=0;
    assert(sz(lv) >= k);
    for (auto& i : lv){
        if (pr >= k) break;
        pr++;
        sort(back[i].begin(), back[i].end(), [&](auto a, auto b){
            return depth[a] < depth[b];
        });
        //cerr << i << ' ' << back[i][0] << ' ' << back[i][1] << '\n';
        vector<int> ans{i}; int c;
        int a=-1;
        if ((depth[i]-depth[back[i][0]]+1)%3){
            a=back[i][0];
            c=par[i];
        } else if ((depth[i]-depth[back[i][1]]+1)%3){
            a=back[i][1];
            c=par[i];
        } else {
            assert(sz(back[i]) >= 2);
            a=back[i][0];
            c=back[i][1];
        }
        while (c != par[a]){
            ans.push_back(c);
            c = par[c];
        }

        assert(sz(ans)%3);
        cout << sz(ans) << '\n';
        for (auto& it : ans) cout << (it+1) << ' ';
        cout << '\n';

    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while (t--) solve();
}