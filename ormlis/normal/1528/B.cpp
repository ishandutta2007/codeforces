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
const int maxN = 1e6 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }


int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}


int rev(int a) {
    return binpow(a, md - 2);
}

int mp[maxN];
vector<int> primes;
int cntd[maxN];
int ldeg[maxN];

void init() {
    for(int i = 2; i < maxN; ++i) {
        if (mp[i] == 0) {
            primes.push_back(i);
            mp[i] = i;
            cntd[i] = 2;
            ldeg[i] = 1;
        }
        for(auto &p : primes) {
            if (p > mp[i]) break;
            if (1ll * p * i >= maxN) break;
            mp[p * i] = p;
            if (p == mp[i]) {
                ldeg[p * i] = ldeg[i] + 1;
                cntd[p * i] = (cntd[i] / ldeg[p * i]) * (ldeg[p * i] + 1);
            } else {
                cntd[p * i] = cntd[i] * 2;
                ldeg[p * i] = 1;
            }
        }
    }
}


void solve() {
    init();
    int n; cin >> n;
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    int sum = 1;
    for(int i = 2; i < n; ++i) {
        sum = add(sum, add(sum, cntd[i]));
    }
    cout << add(sum, cntd[n]);
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