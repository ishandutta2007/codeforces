#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
using namespace std;

const ll INF = 1e18;
const int INFi = 1e9 * 2;
const int maxN = 150001;
ll md = 1000000007;

struct Event {
    int x = 0;
    int i = 0;
    int op = 0;
    bool operator<(Event &b) {
        if(x != b.x) return x < b.x;
        return op > b.op;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> ans(n, 0);
    vector<Event> sc;
    range(i, n) {
        int l, r; cin >> l >> r;
        sc.push_back({l, i, 1});
        sc.push_back({r, i, -1});
    }
    sort(all(sc));
    int bal = 0;
    int flag = 0;
    int answ = 0;
    unordered_set<int> f;
    range(i, n * 2) {
        if(flag && bal == 1 && sc[i].op == 1) ans[*f.begin()]++;
        bal += sc[i].op;
        if (!flag && !bal) ans[*f.begin()]--;
        if (sc[i].op == 1) f.insert(sc[i].i);
        else f.erase(sc[i].i);
        if (sc[i].op == 1 && bal == 1) flag = 0;
        else flag = 1;
        if (bal == 0) answ++;
    }
    int ans2 = -INFi;
    range(i, n) {
        ans2 = max(ans[i], ans2);
    }
    cout << ans2 + answ << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tests; cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}