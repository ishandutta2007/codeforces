#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 5e5 + 1;
int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

vector<int> a;
int h, g;

bool f(int i) {
    int l = 2 * i;
    int r = l + 1;
    if (l >= (1 << h) || (a[r] == 0 && a[l] == 0)) {
        if (i < (1 << g)) return false;
        a[i] = 0;
        return true;
    }
    int nxt = max(a[l], a[r]);
    if (a[l] > a[r]) {
        if (!f(l)) return false;
    } else if (a[r] > a[l]) {
        if (!f(r)) return false;
    }
    a[i] = nxt;
    return true;
}

void solve() {
    cin >> h >> g;
    int n = 1;
    range(_, h) n *= 2;
    a.resize(n + 1, 0);
    range(i, n - 1) cin >> a[i + 1];
    vector<int> q = {1};
    vector<int> ans;
    while (!q.empty()) {
        int v = q.back();
        q.pop_back();
        while (f(v)) {
            ans.push_back(v);
        }
        if (a[v * 2]) q.push_back(v * 2);
        if (a[v * 2 + 1]) q.push_back(v * 2 + 1);
    }
    ll s = 0;
    range(i, n) s += a[i];
    cout << s << '\n';
    range(i, ans.size()) cout << ans[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}