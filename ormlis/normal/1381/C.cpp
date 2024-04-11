#include <bits/stdc++.h>
#include <cstdio>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, x, y; cin >> n >> x >> y;
    vector<int> ans(n, -1);
    vector<vector<int>> color(n+1);
    int colornever = -1;
    range(i, n) {
        int e; cin >> e;
        color[e-1].push_back(i);
    }
    set<pair<int, int>> ss;
    vector<int> sz(n+1);
    range(i, n+1) {
        sz[i] = color[i].size();
        if (sz[i] == 0) colornever = i;
        ss.insert({-sz[i], i});
    }
    range(_, x) {
        auto p = *ss.begin();
        ss.erase(p);
        if (p.first == 0) {
            cout << "NO\n";
            return;
        }
        ans[color[p.second].back()] = p.second;
        color[p.second].pop_back();
        p.first++;
        sz[p.second]--;
        ss.insert(p);
    }
    auto start = ss.begin()->second;
    int next = (start + 1) % (n+1);
    y -= x;
    range(i, n + 1) {
        if (y == 0) break;
        int current = (start + i) % (n + 1);
        for(auto &e: color[current]) {
            if (y == 0) break;
            while (next != start && sz[next] == 0) {
                next = (next + 1) % (n + 1);
            }
            if (next == current || sz[next] == 0) {
                continue;
            }
            ans[color[next][sz[next]-1]] = current;
            sz[next]--;
            y--;
        }
    }
    if (y) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    range(i, n) {
        if (ans[i] == -1) cout << colornever + 1 << " ";
        else cout << ans[i] + 1 << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}