#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;
 
const int inf = 1e17 + 7;
const int max_n = 5e5 + 4;

int n, m;
vector<int> gr[max_n];
int par[max_n];
int sz[max_n];

void dfs(int v) {
    for(int i : gr[v]) {
        if(sz[i] == -1) {
            sz[i] = sz[v] + 1;
            dfs(i);
            par[i] = v;
        }
    }
}

void solve() {
    cin >> n >> m;
    for(int i = 0;i < n;i++) {
        gr[i].clear();
        par[i] = 0;
        sz[i] = -1;
    }

    for(int i = 0;i < m;i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        gr[v1].emplace_back(v2);
        gr[v2].emplace_back(v1);
    }

    sz[0] = 0;
    dfs(0);

    bool path = false;
    for(int i = 0;i < n;i++) {
        if (sz[i] + 1 >= (n + 1) / 2) {
            cout << "PATH" << endl;
            cout << sz[i] + 1 << endl;
            int v = i;
            while(v != 0) {
                cout << v + 1 << " ";
                v = par[v];
            }
            cout << 1 << endl;
            path = true;
            return;
        }
    }
    
    cout << "PAIRING" << endl;
    vector<int> t[n];
    for(int i = 0;i < n;i++) {
        t[sz[i]].emplace_back(i + 1);
    }

    vector<pii> res;
    for(int i = 0;i < n;i++) {
        while(t[i].size() >= 2) {

            int v1 = t[i].back();
            t[i].pop_back();
            int v2 = t[i].back();
            t[i].pop_back();

            res.emplace_back(v1, v2);
        }
    }

    cout << res.size() << endl;

    for(auto i : res)
        cout << i.first << " " << i.second << endl;
}


 
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}