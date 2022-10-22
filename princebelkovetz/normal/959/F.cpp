#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>
#include <string>
#include <numeric>
#pragma GCC optimize("O3")

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7, N = 4e2 + 2, LOG = 20;
int basis[LOG], mlt = 1;

void add(int x) {
    for (int i = LOG - 1; i >= 0; --i) {
        if (x & (1 << i)) {
            if (basis[i] == 0) {
                basis[i] = x;
                return;
            }
            x ^= basis[i];
        }
    }
    assert(x == 0);
    mlt = mlt * 2 % mod;
}

bool able(int x) {
    for (int i = LOG - 1; i >= 0; --i) {
        if (x & (1 << i))
            x ^= basis[i];
    }
    return x == 0;
}

struct query {
    int l, x, i;
    query() {}
    query(int l, int x, int i) :
        l(l), x(x), i(i) {}
    bool operator<(const query& a) const {
        return l < a.l;
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(12);
    
    int n, q; cin >> n >> q;
    vector <int> a(n);
    for (auto& x : a) cin >> x;

    vector <query> qs(q);
    for (int i = 0, l, x; i < q; ++i) {
        cin >> l >> x;
        qs[i] = query(l - 1, x, i);
    }
    sort(qs.begin(), qs.end());

    int curId = -1;
    vector <int> ans(q);
    for (auto& x : qs) {
        while (curId < x.l) {
            curId++;
            add(a[curId]);
        }
        ans[x.i] = (able(x.x) ? mlt : 0);
    }
    for (auto& x : ans) cout << x << '\n';
}