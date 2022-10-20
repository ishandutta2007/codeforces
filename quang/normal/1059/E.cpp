#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, l;
long long s;
int w[N];
vector<int> adj[N];

struct State {
    int deltaCnt;
    long long deltaSum;
    set<pair<int, long long> > s;
    State() {
        deltaSum = 0ll;
        deltaCnt = 0;
        s.clear();
    }

    void add(const State &u) {
        for (auto value : u.s) {
            long long sum = u.deltaSum + value.second - deltaSum;
            int cnt = u.deltaCnt + value.first - deltaCnt;
            s.insert(make_pair(cnt, sum));
        }
    }

    void filter(int w) {
        deltaSum += w;
        deltaCnt++;
        auto it = s.begin();
        while (1) {
            it = s.begin();
            if (it == s.end()) {
                break;
            }
            if (it->second + deltaSum > ::s) {
                s.erase(it);
            } else {
                break;
            }
        }
        while (1) {
            it = s.end();
            if (it == s.begin()) {
                break;
            }
            it--;
            if (it->first + deltaCnt > l) {
                s.erase(it);
            } else {
                break;
            }
        }
    }

    void init(int w) {
        deltaSum = 0;
        deltaCnt = 0;
        s.clear();
        s.insert(make_pair(1, 1ll * w));
    }

    // void debug() {
    //     cout << deltaCnt << " " << deltaSum << endl;
    //     for (auto u : s) {
    //         cout << u.first << " " << u.second << endl;
    //     }
    // }
} state[N];

int id[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> l >> s;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        if (w[i] > s) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        adj[u].push_back(i);
    }
    int cntId = 0;
    int res = 0;
    for (int i = n; i > 0; i--) {
        id[i] = ++cntId;
        for (int u : adj[i]) {
            if (state[id[i]].s.size() < state[id[u]].s.size()) {
                swap(id[i], id[u]);
            }
            state[id[i]].add(state[id[u]]);
        }
        state[id[i]].filter(w[i]);
        if (state[id[i]].s.empty()) {
            state[id[i]].init(w[i]);
            res++;
        }
    }
    cout << res << endl;
    return 0;
}