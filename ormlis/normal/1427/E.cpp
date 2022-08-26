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

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 1e5 + 1;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

void solve() {
    ull n; cin >> n;
    vector<ar<ull, 3>> q;
    auto sum = [&] (ull x, ull y) {
        q.push_back({1, x, y});
        return x + y;
    };

    auto xorr = [&] (ull x, ull y) {
        q.push_back({2, x, y});
        return x ^ y;
    };

    auto geta2aandb = [&] (ull x, ull y) {
        ull z = sum(x, y);
        ull xy = xorr(x, y);
        ull w = sum(z, xy);
        ull xy2 = sum(xy, xy);
        ull as = xorr(xy2, w);
        return as;
    };

    ull n3 = sum(n, n);
    n = xorr(n3, n);

    while(n != 1) {
        ull n2 = n;
        ull i = (1ull<<__lg(n));
        while((n2 & n) != i) {
            n2 = sum(n2, n2);
        }
        ull eq = geta2aandb(n, n2);
        ull e = n;
        while(__builtin_popcount(e) != 1) {
           if (eq & e) {
               e = xorr(e, eq);
           } else {
               e = sum(e, e);
           }
        }
        while(e != i) {
            e = sum(e, e);
        }
        n = xorr(e, n);
    }
    cout << q.size() << "\n";
    for(auto &p: q) {
        cout << p[1] << " ";
        if (p[0] == 1) {
            cout << "+";
        } else {
            cout << "^";
        }
        cout << " " << p[2] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}