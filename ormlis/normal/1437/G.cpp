#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <set>
#include <map>
#include <random>
#include <chrono>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
using namespace std;

const int INFi = 1e9;
const ll INF = 1e18;

struct aho_corasik {
    struct Node {
        map<char, int> to{};
        int link = -1;
        int slink = -1;
        int p = 0;
        char ch = 0;
        multiset<int> ms;
    };

    vector<Node> trie{};

    void build() {
        trie.emplace_back();
    }

    int add(string &s, int val) {
        int v = 0;
        for (auto &c: s) {
            if (!trie[v].to.count(c)) {
                trie[v].to[c] = trie.size();
                trie.emplace_back();
                trie.back().p = v;
                trie.back().ch = c;
            }
            v = trie[v].to[c];
        }
        trie[v].ms.insert(val);
        return v;
    }

    void build_suf_links() {
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto &[c, u] : trie[v].to) {
                q.push(u);
            }
            link(v);

        }
    }

    int link(int v) {
        if (trie[v].link != -1) return trie[v].link;
        if (v == 0 || trie[v].p == 0) return trie[v].link = 0;
        trie[v].link = go(link(trie[v].p), trie[v].ch);
        if (trie[trie[v].link].ms.empty()) trie[v].slink = trie[trie[v].link].slink;
        else trie[v].slink = trie[v].link;
        return trie[v].link;
    }

    int go(int v, char c) {
        if (trie[v].to.count(c)) return trie[v].to[c];
        if (v == 0) return trie[v].to[c] = 0;
        return trie[v].to[c] = go(link(v), c);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> pos(n);
    vector<int> current(n, 0);
    aho_corasik ac;
    ac.build();
    range(i, n) {
        string s;
        cin >> s;
        pos[i] = ac.add(s, 0);
    }
    ac.build_suf_links();
    range(_, m) {
        int tt;
        cin >> tt;
        if (tt == 1) {
            int i, x;
            cin >> i >> x;
            i--;
            ac.trie[pos[i]].ms.erase(ac.trie[pos[i]].ms.find(current[i]));
            current[i] = x;
            ac.trie[pos[i]].ms.insert(current[i]);
            continue;
        }
        string q;
        cin >> q;
        int v = 0;

        int ans = -1;
        for (auto &c: q) {
            v = ac.go(v, c);
            int u = v;
            while (u > 0) {
                if (!ac.trie[u].ms.empty()) ans = max(ans, *ac.trie[u].ms.rbegin());
                u = ac.trie[u].slink;
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}