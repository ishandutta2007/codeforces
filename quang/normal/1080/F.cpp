#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int K = 300010;
const int INF = 2e9;

int n, m, k;
vector<pair<int, int> > a[N];
int cur[N];

bool cmp(const pair<int, int> &u, const pair<int, int> &v) {
    if (u.first != v.first) return u.first < v.first;
    return u.second > v.second;
}

void normalize(vector<pair<int, int> > &u) {
    sort(u.begin(), u.end(), cmp);
    vector<bool> del(u.size(), 0);
    set<pair<int, int> > s;
    for (int i = 0; i < u.size(); i++) {
        pair<int, int> v = u[i];
        while (!s.empty() && s.rbegin()->first >= v.second) {
            del[s.rbegin()->second] = 1;
            s.erase(*s.rbegin());
        }
        s.insert(make_pair(v.second, i)); 
    }
    int now = 0;
    for (int i = 0; i < u.size(); i++) {
        if (!del[i]) {
            u[now++] = u[i];
        }
    }
    u.resize(now);
}

struct IT {
    vector<pair<int, int> > t[N << 2];

    void init(int node, int l, int r) {
        int f = 1;
        set<pair<int, int> > minVal;
        set<pair<int, int> > maxVal;
        for (int i = l; i <= r; i++) {
            cur[i] = 0;
            if (a[i].empty()) {
                f = 0;
                break;
            }
            minVal.insert({a[i][0].first, i});
            maxVal.insert({a[i][0].second, i});
        }
        if (f) {
            t[node].push_back({minVal.begin()->first, maxVal.rbegin()->first});
            while (1) {
                int id = minVal.begin()->second;
                int &now = cur[id];
                minVal.erase({a[id][now].first, id});
                maxVal.erase({a[id][now].second, id});
                now++;
                if (now == a[id].size()) {
                    break;
                }
                minVal.insert({a[id][now].first, id});
                maxVal.insert({a[id][now].second, id});
                t[node].push_back({minVal.begin()->first, maxVal.rbegin()->first});
            }
            normalize(t[node]);
        }
        if (l == r) return;
        int m = l + r >> 1;
        init(node << 1, l, m);
        init(node << 1 | 1, m + 1, r);
    }

    bool get(int node, int l, int r, int x, int y, int low, int high) {
        if (x > r || y < l) return 1;
        if (x <= l && r <= y) {
            auto it = lower_bound(t[node].begin(), t[node].end(), make_pair(low, 0));
            if (it == t[node].end()) return 0;
            return it->second <= high;
        }
        int m = l + r >> 1;
        bool p1 = get(node << 1, l, m, x, y, low, high);
        bool p2 = get(node << 1 | 1, m + 1, r, x, y, low, high);
        return p1 & p2;
    }   
} it;

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= k; i++) {
        int l, r, p;
        scanf("%d %d %d", &l, &r, &p);
        a[p].emplace_back(l, r);
    }
    for (int i = 1; i <= n; i++) {
        normalize(a[i]);
    }
    it.init(1, 1, n);
    while (m--) {
        int a, b, x, y;
        scanf("%d %d %d %d", &a, &b, &x, &y);
        bool ok = it.get(1, 1, n, a, b, x, y);
        puts(ok ? "yes" : "no");
        fflush(stdout);
    }
    return 0;
}