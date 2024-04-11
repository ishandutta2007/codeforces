#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


typedef long long ll;
typedef long double ld;
using namespace std;

//using namespace __gnu_pbds;

const ll INF = 1e18 + 5;
const int INFi = 2e9;
const int maxN = 1e6 + 1;
const int md2 = 998244353;
const int md3 = 1e9 + 7;

vector<int> primes;
int mp[maxN];

void build() {
    for(int i = 2; i < maxN; ++i) {
        if (mp[i] == 0) {
            primes.push_back(i);
            mp[i] = i;
        }
        for(auto &p : primes) {
            if (1ll * p * i >= maxN || p > mp[i]) break;
            mp[p * i] = p;
        }
    }
}

void solve() {
    int d; cin >> d;
    ll ans = 1;
    ans *= (*lower_bound(all(primes), d + 1));
    ans *= (*lower_bound(all(primes), ans + d));
    cout << ans << '\n';
}

int main() {
    build();
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}