#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int maxN = 3e5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int mp[maxN];
vector<int> primes;
void init() {
    for(int i = 2; i < maxN; ++i) {
        if (!mp[i]) {
            mp[i] = i;
            primes.push_back(i);
        }
        for(auto &p : primes) {
            if (1ll * p * i >= maxN || p > mp[i]) break;
            mp[i*p] = p;
        }
    }
}

vector<int> get_primes(int x) {
    vector<int> res;
    while(x != 1) {
        res.push_back(mp[x]);
        while(x % res.back() == 0) x /= res.back();
    }
    return res;
}

int was[maxN];

void solve() {
    init();
    int n, q; cin >> n >> q;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    const int K = 20;
    vector<vector<int>> up(n + 1, vector<int> (K, n));
    int mn = n;
    range(i, maxN) was[i] = n;
    for(int i = n - 1; i >= 0; --i) {
        auto v = get_primes(a[i]);
        for(auto &p : v) {
            mn = min(mn, was[p]);
            was[p] = i;
        }
        up[i][0] = mn;
        for(int j = 1; j < K; ++j) up[i][j] = up[up[i][j - 1]][j - 1];
    }
    range(_, q) {
        int l, r; cin >> l >> r;
        int result = 0;
        l--;
        for(int i = K - 1; i >= 0; --i) {
            if (up[l][i] < r) {
                result |= (1 << i);
                l = up[l][i];
            }
        }
        result++;
        cout << result << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}