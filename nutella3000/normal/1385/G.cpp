#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7;
const int max_n = 2e5 + 1;

int n;
vector<pii> gr[max_n];

int start;

int used[max_n];

void dfs(int v, int pr, bool num, vector<int>& a, int max_used) {
    if (used[v] > max_used) return;
    used[v]++;
    if (num) a.emplace_back(v);
    for(pii i : gr[v]) {
        if (i.first == pr || i.first == start) continue;
        dfs(i.first, v, 1ll ^ num ^ i.second, a, max_used);
    }
}

bool have_sol = true;

int cnt[max_n];

void scan(vector<int> &id) {
    for(int i = 0;i < n;i++) {
        int v;
        cin >> v;
        v--;

        cnt[v]++;

        if (id[v] != -1) {
            gr[id[v]].emplace_back(i, 0);
            gr[i].emplace_back(id[v], 0);
        }else id[v] = i;
    }
}

void solve() {
    cin >> n;

    have_sol = true;
    for(int i = 0;i < n;i++) {
        cnt[i] = 0;
        gr[i].clear();
        used[i] = false;
    }


    vector<int> id1(n, -1), id2(n, -1);

    scan(id1);
    scan(id2);

    bool bad = false;
    for(int i = 0;i < n;i++) if (cnt[i] != 2) bad = true;
    if (bad) {
        cout << -1 << endl;
        return;
    }

    for(int i = 0;i < n;i++) {
        if (id1[i] != -1 && id2[i] != -1) {
            gr[id1[i]].emplace_back(id2[i], 1);
            gr[id2[i]].emplace_back(id1[i], 1);
        }
    }

    vector<int> res;

    for(int i = 0;i < n;i++) {
        if (used[i]) continue;
        start = i;
        vector<int> one, two;
        dfs(i, i, false, one, 0ll);
        dfs(i, i, true, two, 1ll);

        if (two.size() < one.size()) swap(one, two);
        for(int j : one) res.emplace_back(j);
    }
    
    cout << res.size() << endl;
    for(int i : res) cout << i + 1 << " ";
    cout << endl;
}



signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}