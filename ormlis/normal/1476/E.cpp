#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


typedef long long ll;
typedef long double ld;
using namespace std;

// using namespace __gnu_pbds;

const ll INF = 1e18 + 5;
const int INFi = 2e9;
const int maxN = 1e6 + 1000;
const int md = 1e9 + 123;
const int md2 = 1e9 + 7;

inline int h(const char &s) {
    if (s != '_') return s - 'a' + 1;
    return 0;
}

int h(const string &s) {
    int res = 0;
    range(i, (int) s.size()) {
        res *= 27;
        res += h(s[i]);
    }
    return res;
}

vector<int> g[maxN];
vector<int> ts;
int used[maxN];
int pos[maxN];

void dfs(int v) {
    used[v] = 1;
    for(auto &u : g[v]) {
        if (used[u]) continue;
        dfs(u);
    }
    pos[v] = ts.size();
    ts.push_back(v);
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    map<int, int> num;
    range(i, n) {
        string s;
        cin >> s;
        int w = h(s);
        num[w] = i;
    }
    vector<int> st = {1, 27, 27 * 27, 27 * 27 * 27};
    range(i, m) {
        string s;
        cin >> s;
        int mt;
        cin >> mt;
        mt--;
        int w = h(s);
        set<int> formt;
        bool f = false;
        range(mask, 1 << k) {
            int w2 = w;
            range(j, k) {
                if ((1 << j) & mask) w2 -= h(s[j]) * st[k - 1 - j];
            }
            if (num.count(w2)) {
                if (num[w2] == mt) {
                    f = true;
                    continue;
                }
                g[num[w2]].push_back(mt);
            }
        }
        if (!f) {
            cout << "NO\n";
            return;
        }
    }
    range(i, n) {
        if (!used[i]) {
            dfs(i);
        }
        for(auto &u : g[i]) {
            if (pos[u] > pos[i]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    for(auto &i : ts) cout << i + 1 << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}