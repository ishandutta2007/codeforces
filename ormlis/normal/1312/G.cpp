#include <iostream>
#include <random>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cmath>
#include <chrono>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 2e7;
ll md = 1000000007;

//double getTime() { return clock() / (double) CLOCKS_PER_SEC;};

struct Node {
    bool good = 0;
    int l = -1, r = -1;
    map<int, int> to{};

    Node() = default;
};

vector<Node> s;
vector<int> ans;
vector<int> order;

void dfs(int v) {
    int j = order.size();
    if (s[v].good) {
        order.push_back(v);
    }
    for (auto &u: s[v].to) {
        dfs(u.second);
    }
    if (order.size() != j) {
        s[v].l = j;
        s[v].r = order.size() - 1;
    }
}

void dfs2(int v, int prev, int x) {
    if (s[v].good) {
        ans[v] = min(prev + 1, x);
    } else ans[v] = prev + 1;
    if (x > ans[v] + 1) x = ans[v] + 1;
    for (auto &u: s[v].to) {
        int x2 = x + s[u.second].l - s[v].l;
        dfs2(u.second, ans[v], x2);
    }
}


void solve() {
    int n;
    cin >> n;
    s.resize(n + 1);
    ans.resize(n + 1);
    range(i, n) {
        int p;
        char c;
        cin >> p >> c;
        s[p].to[c - 'a'] = i + 1;
    }
    int k;
    cin >> k;
    vector<int> a(k);
    range(i, k) {
        cin >> a[i];
        s[a[i]].good = 1;
    }
    dfs(0);
    dfs2(0, -1, 1);
    range(i, k) cout << ans[a[i]] << " ";
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