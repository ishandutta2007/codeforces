#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <queue>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 200001;
ll md = 1000000007;
int n, m, k;
vector<int> g[maxN];

vector<int> bfs(int v) {
    vector<int> d(n + 1, INFi);
    d[v] = 0;
    queue<int> q;
    q.push(v);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto u2: g[u]) {
            if (d[u2] > d[u] + 1) {
                q.push(u2);
                d[u2] = d[u] + 1;
            }
        }
    }
    return d;
}

vector<int> a, b;

bool comp(int &x, int &y) {
    return a[x] - b[x] < a[y] - b[y];
}

void solve() {
    cin >> n >> m >> k;
    vector<int> s(k, 0);
    range(i, k) cin >> s[i];
    range(i, m) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    a = bfs(1);
    b = bfs(n);
    sort(all(s), comp);
    int ans = 0;
    int maxa1 = -INFi, maxb1 = -INFi;
    int maxia1 = 1;
    int maxib1 = 1;
    int i = -1, j = -1;
    for(auto x: s) {
        if (ans <= b[x] + maxa1) {
            i = x;
            j = maxia1;
        }
        ans = max(ans, b[x] + maxa1);
        if (maxa1 <= a[x]) maxia1 = x;
        maxa1 = max(maxa1, a[x]);
    }
    reverse(all(s));
    for(auto x: s) {
        if (ans <= a[x] + maxb1) {
            i = x;
            j = maxib1;
        }
        ans = max(ans, a[x] + maxb1);
        if (maxb1 <= b[x]) {
            maxib1 = x;
        }
        maxb1 = max(maxb1, b[x]);
    }
    g[i].push_back(j);
    g[j].push_back(i);
    auto sd = bfs(1);
    cout << sd[n];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests=1;
    range(_, tests) {
        solve();
    }
    return 0;
}