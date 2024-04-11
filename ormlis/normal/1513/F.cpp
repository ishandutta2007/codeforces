#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <random>
#include <chrono>
#include <cassert>
#include <iomanip>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const ll INF = 2e18 + 5;
const int INFi = 1e8;
const int maxN = 3e5 + 100;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

struct fenwick {
    vector<ll> fenw{};
    int n;

    void build(int k) {
        n = k + 10;
        fenw.resize(n, INF);
    }

    void upd(int i, ll x) {
        for(; i < n; i |= (i + 1)) fenw[i] = min(fenw[i], x);
    }

    ll get(int i) {
        ll res = INF;
        for(; i >= 0; i = (i & (i + 1)) - 1) res = min(res, fenw[i]);
        return res;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    range(i, n) cin >> a[i];
    range(i, n) cin >> b[i];
    ll answer = INF;
    range(_, 2) {
        ll su = 0;
        range(i, n) su += abs(a[i] - b[i]);
        auto A = a;
        answer = min(answer, su);
        sort(all(A));
        A.resize(unique(all(A)) - A.begin());
        auto B = b;
        sort(all(B));
        B.resize(unique(all(B)) - B.begin());
        vector<int> ord(n);
        iota(all(ord), 0);
        sort(all(ord), [&](const int &i, const int &j) {
            return a[i] < a[j];
        });
        auto ord2 = ord;
        sort(all(ord2), [&](const int &i, const int &j) {
            return b[i] < b[j];
        });
        fenwick f1, f2;
        f1.build(n);
        f2.build(n);
        int j = 0;
        for (auto &i : ord) {
            while (j < n && b[ord2[j]] <= a[i]) {
                int lw = lower_bound(all(A), a[ord2[j]]) - A.begin();
                f1.upd(n + 2 - lw, -b[ord2[j]] + a[ord2[j]] - abs(-b[ord2[j]] + a[ord2[j]]));
                f2.upd(lw, -b[ord2[j]] - a[ord2[j]] - abs(-b[ord2[j]] + a[ord2[j]]));
                j++;
            }
            ll res = su - abs(a[i] - b[i]) + a[i];
            int lw = upper_bound(all(A), b[i]) - A.begin();
            lw--;
            answer = min(answer, res + f2.get(lw) + b[i]);
            lw++;
            answer = min(answer, res + f1.get(n + 2 - lw) - b[i]);
            // a[i] - b[j] + abs(a[j] - b[i])
        }
        swap(a, b);
    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}