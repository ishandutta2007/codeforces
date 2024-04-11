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
const int md = 1e9 + 7;

int mp[maxN];
vector<int> primes;

void init() {
    for (int i = 2; i < maxN; ++i) {
        if (!mp[i]) {
            mp[i] = i;
            primes.push_back(i);
        }
        for (auto &p : primes) {
            if (1ll * p * i >= maxN || p > mp[i]) break;
            mp[i * p] = p;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    map<vector<int>, int> cnt;
    range(i, n) {
        vector<int> stk;
        int a;
        cin >> a;
        while (a != 1) {
            if (stk.empty() || stk.back() != mp[a]) stk.push_back(mp[a]);
            else stk.pop_back();
            a /= mp[a];
        }
        cnt[stk]++;
    }
    int ans0 = 0, ans1 = 0;
    for(auto &[s, c] : cnt) {
        ans0 = max(ans0, c);
        if (c % 2 == 0 || s.empty()) ans1 += c;
    }
    int q; cin >> q;
    ans1 = max(ans0, ans1);
    range(_, q) {
        ll w; cin >> w;
        if (w == 0) cout << ans0 << '\n';
        else cout << ans1 << '\n';
    }
}

int main() {
    init();
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