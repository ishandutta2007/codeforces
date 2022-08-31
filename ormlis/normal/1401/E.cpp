#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

struct fenwick {
    int n{};
    vector<ll> fenw{};

    void build(int k) {
        n = k;
        fenw.resize(n);
    }

    void upd(int i, ll x) {
        for (; i < n; i = i | (i + 1)) fenw[i] += x;
    }

    int get(int i) {
        ll res = 0;
        for (; ~i; i = (i & (i + 1)) - 1) res += fenw[i];
        return res;
    }

    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ar<int, 3>> gor(n);
    range(i, n) range(j, 3) cin >> gor[i][j];
    n += 2;
    gor.push_back({(int)1e6, 0, (int)1e6});
    gor.push_back({(int)0, 0, (int)1e6});
    vector<ar<int, 3>> scli;
    range(i, n) {
        scli.push_back({gor[i][1], -1, gor[i][0]});
        scli.push_back({gor[i][2], 1, gor[i][0]});
    }
    sort(all(scli));
    vector<ar<int, 3>> vert(m);
    range(i, m) range(j, 3) cin >> vert[i][j];
    m += 2;
    vert.push_back({(int)1e6, 0, (int)1e6});
    vert.push_back({(int)0, 0, (int)1e6});
    sort(all(vert));
    vector<int> need;
    range(i, n * 2) need.push_back(scli[i][0]);
    range(i, m) need.push_back(vert[i][0]);
    sort(all(need));
    need.resize(unique(all(need)) - need.begin());
    int i = 0, j = 0;
    fenwick f;
    f.build(1e6 + 1);
    ll ans = 1 - n - m;
    for(auto &x: need) {
        while (i < scli.size() && scli[i][0] == x && scli[i][1] == -1) {
            f.upd(scli[i][2], 1);
            i++;
        }
        while(j < vert.size() && vert[j][0] == x) {
            ans += f.get(vert[j][1], vert[j][2]);
            j++;
        }
        while (i < scli.size() && scli[i][0] == x && scli[i][1] == 1) {
            f.upd(scli[i][2], -1);
            i++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
//    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}