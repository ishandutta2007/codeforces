//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define sz(a) ((ll)(a).size())
#define X first
#define Y second

using ll = long long;
using ull = unsigned long long;
using dbl = long double;

vector<tuple<int, string, int>> answer;
const int maxbit = 40;

void get_degrees(int x) {
    for (int d = 0; d < maxbit; ++d) {
        int t = x << d;
        answer.emplace_back(t, "+", t);
    }
}

void getmul(int x, int k) {
    int sum = 0;
    for (int bit = 0; bit < maxbit; ++bit) {
        if (k & (1LL << bit)) {
            if (sum > 0) {
                answer.emplace_back(sum, "+", x << bit);
            }
            sum += x << bit;
        }
    }
    assert(sum == k * x);
}

int solve(int x) {
    assert(x > 1 && (x % 2 == 1));
    int need = 1;
    while (need <= x) need *= 2;
    need = need / 2 - 1;
    
    get_degrees(x);
    
    vector<int> basis;
    basis.reserve(60);
    for (int k = 1; ; ++k) {
        int num = k * x;
        for (auto vec: basis) {
            num = min(num, num ^ vec);
        }
        if (num == 0) {
            continue;
        }
        getmul(x, k);
        int current = k * x;
        for (auto &vec: basis) {
            if ((current ^ vec) < current) {
                answer.emplace_back(vec, "^", current);
                current ^= vec;
            }
            if (vec < current) {
                swap(vec, current);
            }
        }
        assert(current > 0);
        basis.push_back(current);
        if (current > need) {
            continue;
        }
        int t = current;
        while (t <= need) {
            answer.emplace_back(t, "+", t);
            t *= 2;
        }
        answer.emplace_back(x, "^", t);
        int result = x ^ t;
        assert(result <= need && (result & 1));
        return result;
    }
}

void solve() {
    int x;
    cin >> x;
    while (x > 1) {
        x = solve(x);
    }
    cout << sz(answer) << endl;
    for (auto [x, op, y]: answer) {
        cout << x << ' ' << op << ' ' << y << '\n';
    }
}

signed main() {
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    // assert(freopen("output.txt", "w", stdout));
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);

    int T = 1;
    // cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }

#ifdef LOCAL
    cout << endl << endl << "time = " << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
}