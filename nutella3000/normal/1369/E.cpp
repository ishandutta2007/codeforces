#include <bits/stdc++.h>
using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7, mod = 1e9 + 7;

int n, m;
vector<int> w, res;
vector<set<int>> s;
vector<bool> used;
vector<pii> x;
set<int> lower;

void check(int id) {
    if (s[id].size() == 0 || s[id].size() > w[id]) lower.erase(id);
    else lower.emplace(id);
}


void solve() {
    cin >> n >> m;
    w.resize(n);
    s.resize(n);
    used.resize(m);
    x.resize(m);

    for(int i = 0;i < n;i++) cin >> w[i];

    for(int i = 0;i < m;i++) {
        cin >> x[i].first >> x[i].second;
        x[i].first--;
        x[i].second--;
        s[x[i].first].emplace(i);
        s[x[i].second].emplace(i);
        check(x[i].first);
        check(x[i].second);
    }

    while(lower.size()) {
        int v = *lower.begin();
        vector<int> temp;
        for(int i : s[v]) temp.emplace_back(i);
        for(int i : temp) {
            s[x[i].first].erase(i);
            s[x[i].second].erase(i);
            check(x[i].first);
            check(x[i].second);
            res.emplace_back(i);
        }
    }
    if (res.size() == m) {
        cout << "ALIVE" << endl;
        for(int i = res.size() - 1;i >= 0;i--) cout << res[i] + 1 << " ";
    }else cout << "DEAD";
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}