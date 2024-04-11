#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <bitset>
#include <iomanip>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 100001;
ll md = 1000000007;

vector<int> lcd;
vector<int> g[maxN]; int h[maxN];
int n;
int first[maxN];

void dfs(int v, int p, int h1) {
    first[v] = lcd.size();
    lcd.push_back(v);
    h[v] = h1;
    for(auto x: g[v]) {
        if (x == p) continue;
        dfs(x, v, h1 + 1);
        lcd.push_back(v);
    }
}

pair<int, int> tree[2000020], arr[2000000];


void make(int v, int L, int R) {
    if (R - L == 1) {
        tree[v] = arr[L];
        return;
    }
    make(v * 2, L, (L + R) / 2);
    make(v * 2 + 1, (L + R) / 2, R);
    tree[v] = min(tree[v * 2 + 1], tree[v * 2]);
}


pair<int, int> get(int v, int l, int r, int L, int R) {
    if (l >= R || L >= r) {
        return {INFi, -1};
    }
    if (l <= L && R <= r) {
        return tree[v];
    }
    auto a = get(v * 2, l, r, L, (L + R) / 2);
    auto b = get(v * 2 + 1, l, r, (L + R) / 2, R);
    return min(a, b);
}
int n2;
int lca(int x, int y) {
    int h3;
    int f1 = first[x];
    int f2 = first[y];
    if (f1 > f2) swap(f1, f2);
    h3 = h[get(1, f1, f2 + 1, 0, n2).second];
    return h[x] + h[y] - h3 * 2;
}

int check(int path, int k) {
    if (path <= k && path % 2 == k % 2) return 1;
    return 0;
}

void solve() {
    cin >> n;
    range(i, n - 1) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1, 0);
    n2 = lcd.size();
    range(i, n2) arr[i] = {h[lcd[i]], lcd[i]};
    make(1, 0, n2);
    int q; cin >> q;
    range(i, q) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        int lcaab = lca(a, b);
        int lcaax = lca(a, x);
        int lcaay = lca(a, y);
        int lcabx = lca(b, x);
        int lcaby = lca(b, y);
        if (check(lcaab, k) || check(lcaax + lcaby + 1, k) || check(lcaay + lcabx + 1, k)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
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