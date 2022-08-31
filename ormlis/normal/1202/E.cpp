#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 3e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

struct Aho {
    struct Node {
        map<char, int> to{};
        char ch{};
        int p = 0, link = -1;
        int cnt = 0;
        map<char, int> go{};
    };

    vector<Node> t = {{}};

    void add(const string &s) {
        int v = 0;
        for (auto &a: s) {
            if (!t[v].to.count(a)) {
                t[v].to[a] = t.size();
                t.emplace_back();
                t.back().ch = a;
                t.back().p = v;
            }
            v = t[v].to[a];
        }
        t[v].cnt++;
    }

    void init() {
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            get_link(v);
            for(auto &x: t[v].to) q.push(x.second);
        }
    }

    int go(int v, char c) {
        if (!t[v].go.count(c)) {
            if (t[v].to.count(c)) {
                t[v].go[c] = t[v].to[c];
            } else {
                t[v].go[c] = v == 0 ? 0 : go(get_link(v), c);
            }
        }
        return t[v].go[c];
    }

    int get_link(int v) {
        if (t[v].link == -1) {
            if (v == 0 || t[v].p == 0) {
                t[v].link = 0;
            } else {
                t[v].link = go(get_link(t[v].p), t[v].ch);
            }
            t[v].cnt += t[t[v].link].cnt;
        }
        return t[v].link;
    }

    vector<int> get_cnt(const string &text) {
        vector<int> res(text.size());
        int v = 0;
        range(i, (int)text.size()) {
            v = go(v, text[i]);
            res[i] = t[v].cnt;
        }
        return res;
    }
};

void solve() {
    string t; cin >> t;
    Aho ez1, ez2;
    int n; cin >> n;
    range(i, n) {
        string s; cin >> s;
        ez1.add(s);
        reverse(all(s));
        ez2.add(s);
    }
    ez1.init();
    ez2.init();
    auto res1 = ez1.get_cnt(t);
    reverse(all(t));
    auto res2 = ez2.get_cnt(t);
    reverse(all(res2));
    ll ans = 0;
    range(i, (int)res1.size() - 1) {
        ans += 1ll * res1[i] * res2[i+1];
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}