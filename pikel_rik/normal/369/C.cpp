#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5;

int n;
vi g[N + 1];
set<pi> s;
set<int> ans;

void dfs(int i, int p, int last) {
    if (s.find({i, p}) != s.end() or s.find({p, i}) != s.end()) {
        ans.erase(last);
        ans.insert(i);
        last = i;
    }

    for (auto &x : g[i]) {
        if (x == p) continue;
        dfs(x, i, last);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y, t;
        cin >> x >> y >> t;

        g[x].emplace_back(y);
        g[y].emplace_back(x);
        if (t == 2) {
            s.insert({x, y});
            s.insert({y, x});
        }
    }

    dfs(1, 0, 0);

    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i << " ";
    }

    return 0;
}