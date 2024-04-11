#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

int dsu[maxN];
bool open[maxN];
void init() {
    range(i, maxN) dsu[i] = i;
    range(i, maxN) open[i] = true;
}

int get_dsu(int a) {
    return dsu[a] == a ? a : dsu[a] = get_dsu(dsu[a]);
}

bool Unio(int x, int y) {
    int a = get_dsu(x), b = get_dsu(y);
    if (!open[a] && !open[b]) return false;
    if (a == b) {
        open[a] = false;
        return true;
    }
    if (rand() % 2) swap(a, b);
    dsu[b] = a;
    open[a] &= open[b];
    return true;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<ar<int, 3>> prs(m);
    range(i, m) {
        cin >> prs[i][1] >> prs[i][2] >> prs[i][0];
    }
    sort(rall(prs));
    ll ans = 0;
    init();
    range(i, m) {
        if (Unio(prs[i][1], prs[i][2])) ans += prs[i][0];
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