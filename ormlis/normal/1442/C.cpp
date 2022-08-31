#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;
using namespace __gnu_pbds;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 2e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

int n, m;
vector<int> g1[maxN], g2[maxN];
int start, finish;

void read() {
    range(i, m) {
        int a, b;
        cin >> a >> b;
        g1[a].push_back(b);
        g2[b].push_back(a);
    }
    start = 1;
    finish = n;
}

int dist[maxN][20];

int djsk() {
    for (int i = 1; i <= n; ++i) {
        range(j, 20) dist[i][j] = INFi;
    }
    dist[start][0] = 0;
    set<pair<int, pair<int, int>>> q;
    for (int i = 1; i <= n; ++i) {
        range(j, 20) {
            q.insert({dist[i][j], {i, j}});
        }
    }
    while (!q.empty()) {
        int d = q.begin()->first;
        int i = q.begin()->second.first;
        int j = q.begin()->second.second;
        q.erase(q.begin());
        if (d == INFi) break;
        if (j & 1) {
            for (auto &u: g2[i]) {
                if (dist[u][j] > d + 1) {
                    q.erase({dist[u][j], {u, j}});
                    dist[u][j] = d + 1;
                    q.insert({dist[u][j], {u, j}});
                }
            }
        } else {
            for (auto &u: g1[i]) {
                if (dist[u][j] > d + 1) {
                    q.erase({dist[u][j], {u, j}});
                    dist[u][j] = d + 1;
                    q.insert({dist[u][j], {u, j}});
                }
            }
        }
        if (j != 19) {
            int newd = d + (1 << j);
            if (dist[i][j + 1] > newd) {
                q.erase({dist[i][j + 1], {i, j + 1}});
                dist[i][j + 1] = newd;
                q.insert({dist[i][j + 1], {i, j + 1}});
            }
        }
    }
    int ans = INFi;
    range(i, 20) {
        ans = min(ans, dist[finish][i]);
    }
    return ans;
}

pair<int, int> dist2[maxN][2];

pair<int, int> check_large() {
    for (int i = 1; i <= n; ++i) {
        dist2[i][0] = dist2[i][1] = {INFi, INFi};
    }
    dist2[start][0] = {0, 0};
    set<pair<pair<int, int>, pair<int, int>>> q;
    for (int i = 1; i <= n; ++i) {
        range(j, 2) {
            q.insert({dist2[i][j], {i, j}});
        }
    }
    while (!q.empty()) {
        auto d = q.begin()->first;
        int i = q.begin()->second.first;
        int j = q.begin()->second.second;
        q.erase(q.begin());
        if (d.first == INFi) break;
        if (j) {
            d.second++;
            for (auto &u: g2[i]) {
                if (dist2[u][j] > d) {
                    q.erase({dist2[u][j], {u, j}});
                    dist2[u][j] = d;
                    q.insert({dist2[u][j], {u, j}});
                }
            }
            d.second--;
        } else {
            d.second++;
            for (auto &u: g1[i]) {
                if (dist2[u][j] > d) {
                    q.erase({dist2[u][j], {u, j}});
                    dist2[u][j] = d;
                    q.insert({dist2[u][j], {u, j}});
                }
            }
            d.second--;
        }
        d.first++;
        int j2 = j ^ 1;
        if (dist2[i][j2] > d) {
            q.erase({dist2[i][j2], {i, j2}});
            dist2[i][j2] = d;
            q.insert({dist2[i][j2], {i, j2}});
        }
    }
    pair<int, int> ans = min(dist2[finish][1], dist2[finish][0]);
    return ans;
}

int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}

int rev(int a) {
    return binpow(a, md - 2);
}


void solve() {
    cin >> n >> m;
    read();
    int answer1 = djsk();
    pair<int, int> answer2 = check_large();
    if (answer1 == INFi) {
        cout << add(sub(binpow(2, answer2.first), 1), answer2.second) << "\n";
        return;
    }
    cout << answer1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}