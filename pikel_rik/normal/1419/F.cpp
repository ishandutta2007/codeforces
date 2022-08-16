#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <memory.h>

using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1000 + 5;

int n;
pair<int, int> a[N];
vector<pair<int, int>> g[N];

int cur_id, id[N], t;
vector<int> points[4];
bool visited[N];

void dfs(int x) {
    id[x] = cur_id;
    points[id[x]].push_back(x);
    visited[x] = true;
    for (auto& [i, w] : g[x]) {
        if (!visited[i] and w <= t) {
            dfs(i);
        }
    }
}

struct seg {
    pair<int, int> p1, p2;
    char mask;
    seg(const pair<int, int> &p1, const pair<int, int> &p2, char mask) : p1(p1), p2(p2), mask(mask) {}
};

int dist(const pair<int, int>& x, const pair<int, int>& y) {
    return abs(x.first - y.first) + abs(x.second - y.second);
}

bool f(int dummy) {
    t = dummy;
    cur_id = 0;

    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (cur_id == 4) {
                return false;
            }
            points[cur_id].clear();
            dfs(i);
            cur_id++;
        }
    }

    if (cur_id == 1) {
        return true;
    } else if (cur_id == 2) {
        for (int i : points[0]) {
            for (int j : points[1]) {
                auto [x1, y1] = a[i];
                auto [x2, y2] = a[j];
                if (x1 == x2 and abs(y1 - y2) <= 2ll * t) {
                    return true;
                } else if (y1 == y2 and abs(x1 - x2) <= 2ll * t) {
                    return true;
                } else if (abs(x1 - x2) <= t and abs(y1 - y2) <= t) {
                    return true;
                }
            }
        }
    } else {
        vector<seg> segments;
        set<int> seen;
        for (int rot = 0; rot < 2; rot++) {
            for (int i = 0; i < n; i++) {
                if (!seen.count(a[i].first)) {
                    seen.insert(a[i].first);
                    vector<int> temp;
                    for (int j = 0; j < n; j++) {
                        if (a[j].first == a[i].first) {
                            temp.push_back(j);
                        }
                    }

                    sort(temp.begin(), temp.end(), [&](int ii, int jj) {
                        return a[ii].second < a[jj].second;
                    });

                    for (int j = 1; j < temp.size(); j++) {
                        if (id[temp[j]] != id[temp[j - 1]]) {
                            if (rot == 1) {
                                swap(a[temp[j]].first, a[temp[j]].second);
                                swap(a[temp[j - 1]].first, a[temp[j - 1]].second);
                            }
                            segments.emplace_back(a[temp[j]], a[temp[j - 1]], (1 << id[temp[j]]) | (1 << id[temp[j - 1]]));
                            if (rot == 1) {
                                swap(a[temp[j]].first, a[temp[j]].second);
                                swap(a[temp[j - 1]].first, a[temp[j - 1]].second);
                            }
                        }
                    }
                }
            }
            seen.clear();
            for (int j = 0; j < n; j++) {
                swap(a[j].first, a[j].second);
            }
        }

        for (auto& s : segments) {
            if (s.p1.first > s.p2.first)
                swap(s.p1.first, s.p2.first);
            if (s.p1.second > s.p2.second)
                swap(s.p1.second, s.p2.second);
        }

        if (cur_id == 3) {
            for (const auto &s : segments) {
                int val = ((s.mask & 1) ? ((s.mask & 2) ? 2 : 1) : 0);
                for (int i : points[val]) {
                    auto [x, y] = a[i];
                    if (s.p1.first == s.p2.first) {
                        pair<int, int> p = make_pair(s.p1.first, y);
                        if (dist(p, s.p1) <= t and dist(p, s.p2) <= t and dist(p, a[i]) <= t) {
                            return true;
                        }
                    } else {
                        pair<int, int> p = make_pair(x, s.p1.second);
                        if (dist(p, s.p1) <= t and dist(p, s.p2) <= t and dist(p, a[i]) <= t) {
                            return true;
                        }
                    }
                }
            }
        } else {
            for (int i = 0; i < segments.size(); i++) {
                const auto& s1 = segments[i];
                for (int j = i + 1; j < segments.size(); j++) {
                    const auto& s2 = segments[j];
                    if ((s1.mask | s2.mask) == 15) {
                        if (s1.p1.first == s1.p2.first and s2.p1.second == s2.p2.second) {
                            pair<int, int> p = make_pair(s1.p1.first, s2.p1.second);
                            if (dist(p, s1.p1) <= t and dist(p, s1.p2) <= t and dist(p, s2.p1) <= t and dist(p, s2.p2) <= t) {
                                return true;
                            }
                        } else if (s1.p1.second == s1.p2.second and s2.p1.first == s2.p2.first) {
                            pair<int, int> p = make_pair(s2.p1.first, s1.p1.second);
                            if (dist(p, s1.p1) <= t and dist(p, s1.p2) <= t and dist(p, s2.p1) <= t and dist(p, s2.p2) <= t) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        for (int j = 0; j < i; j++) {
            if (a[j].first == a[i].first) {
                g[i].emplace_back(j, abs(a[i].second - a[j].second));
                g[j].emplace_back(i, abs(a[i].second - a[j].second));
            } else if (a[j].second == a[i].second) {
                g[i].emplace_back(j, abs(a[i].first - a[j].first));
                g[j].emplace_back(i, abs(a[i].first - a[j].first));
            }
        }
    }

    int lo = 1, hi = (int)2e9;

    if (!f(hi)) {
        cout << "-1\n";
        return 0;
    }

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (f(mid))
            hi = mid;
        else lo = mid + 1;
    }
    cout << lo << '\n';
    return 0;
}