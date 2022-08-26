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
typedef double ld;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int maxN = 1e6 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

int phi[maxN];
int mp[maxN];
vector<int> primes;

void init() {
    for(int i = 2; i < maxN; ++i) {
        if (!mp[i]) {
            mp[i] = i;
            primes.push_back(i);
            phi[i] = i - 1;
        }
        for(auto &p : primes) {
            if (1ll * p * i >= maxN || p > mp[i]) break;
            mp[p * i] = p;
            if (p == mp[i]) {
                phi[p * i] = phi[i] * p;
            } else {
                phi[p * i] = phi[i] * (p - 1);
            }
        }
    }
}

void solve() {
    int n, k; cin >> n >> k;
    if (k == 1) {
        cout << "3\n";
        return;
    }
    init();
    vector<int> ord;
    k++;
    for(int i = 2; i <= n; ++i) ord.push_back(phi[i]);
    sort(all(ord));
    ord.resize(k);
    cout << accumulate(all(ord), 0ll) + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}