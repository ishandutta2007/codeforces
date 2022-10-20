#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int INF = (int)1e9 + 10;

int t, T;
int n, m;
vector<int> adj[N];
pair<int, int> bounds[N];

inline void outputFail() {
    cout << "IMPOSSIBLE\n";
    exit(0);
}

struct Data {
    vector<int> ls;
    int l, r;

    Data() {
        l = 0;
        r = INF;
    }

    void swap(Data &o) {
        ls.swap(o.ls);
        ::swap(l, o.l);
        ::swap(r, o.r);
    }

    void check() {
        if (l > r) {
            outputFail();
        }
    }

    void debug() {
        cerr << "ls: ";
        for (int u : ls) cerr << u << ' ';
        cerr << '\n';
        cerr << l << ' ' << r << '\n';
    }
};

vector<pair<Data, Data>> components;
int used[N];

void dfs(int u, int side) {
    used[u] = side;
    Data &now = side ? components.back().second : components.back().first;
    now.ls.push_back(u);
    now.l = max(now.l, bounds[u].first);
    now.r = min(now.r, bounds[u].second);
    for (int v : adj[u]) {
        if (used[v] >= 0) {
            if (used[v] == side) {
                outputFail();
            }
        } else {
            dfs(v, side ^ 1);
        }
    }
}

pair<int, int> intersect(int l, int r, int ll, int rr) {
    l = max(l, ll);
    r = min(r, rr);
    if (l <= r) return {l, r};
    return {-1, -1};
}

pair<int, int> getVal(int l, int r, int ll, int rr) {
    pair<int, int> res(l, ll);
    int now = l + ll;
    assert(now <= T);
    if (now >= t) return res;
    int delta = t - now;
    if (delta <= rr - ll) {
        res.second += delta;
        return res;
    }
    res.second = rr;
    now = res.first + res.second;
    delta = t - now;
    res.first += delta;
    assert(res.first <= res.second);
    return res;
}

int inGroup[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t >> T;
    cin >> n >> m;
    int maxVal = INF;
    for (int i = 1; i <= n; i++) {
        cin >> bounds[i].first >> bounds[i].second;
        maxVal = min(maxVal, bounds[i].second);
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(used, -1, sizeof used);
    for (int i = 1; i <= n; i++) {
        if (used[i] < 0) {
            components.push_back({Data(), Data()});
            dfs(i, 0);
        }
    }
    vector<int> tstamps;
    vector<pair<int, int>> events;
    multiset<int> l, r;
    int minVal = 0;
    for (int i = 0; i < components.size(); i++) {
        auto &u = components[i];
        if (u.first.l > u.second.l) {
            u.first.swap(u.second);
        }
        minVal = max(minVal, min(u.first.l, u.second.l));
        u.first.check();
        u.second.check();
        if (u.first.l <= maxVal) tstamps.push_back(u.first.l);
        if (u.second.l <= maxVal) tstamps.push_back(u.second.l);
        l.insert(u.second.l);
        r.insert(u.second.r);
        events.push_back({u.second.l, i});
    }
    tstamps.push_back(maxVal + 1);
    sort(tstamps.begin(), tstamps.end());
    sort(events.begin(), events.end());
    tstamps.resize(unique(tstamps.begin(), tstamps.end()) - tstamps.begin());
    pair<int, int> res = {-1, -1};
    int cur = 0;

    auto modify = [&](int id) {
        auto &u = components[id];
        l.erase(l.find(u.second.l));
        r.erase(r.find(u.second.r));
        l.insert(0);
        r.insert(max(u.second.r, u.first.r));
    };

    for (int i = 0; i + 1 < tstamps.size(); i++) {
        while (cur < events.size() && events[cur].first <= tstamps[i]) {
            modify(events[cur].second);
            cur++;
        }
        if (tstamps[i] < minVal) continue;
        if (max(tstamps[i], *l.rbegin()) > *r.begin()) continue;
        int ll = tstamps[i] + max(tstamps[i], *l.rbegin());
        int rr = tstamps[i + 1] - 1 + *r.begin();
        pair<int, int> foo = intersect(ll, rr, t, T);
        if (foo.first != -1) {
            res = getVal(tstamps[i], tstamps[i + 1] - 1, max(tstamps[i], *l.rbegin()), *r.begin());
            break;
        }
    }
    if (res.first == -1) outputFail();
    for (auto u : components) {
        int id = 0;
        if (res.first >= u.second.l) {
            if (u.first.r > u.second.r) {
                id = 1;
            }
        }
        for (auto v : u.first.ls) inGroup[v] = id + 1;
        for (auto v : u.second.ls) inGroup[v] = (id ^ 1) + 1;
    }
    cout << "POSSIBLE\n";
    cout << res.first << ' ' << res.second << '\n';
    for (int i = 1; i <= n; i++) {
        cout << inGroup[i];
    }
    cout << endl;
    return 0;
}