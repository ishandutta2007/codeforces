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
const int maxN = 3e5 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m, p; cin >> n >> m >> p;
    vector<ll> a(n);
    range(i, n) {
        for(ll j = 0; j < m; ++j){
            char x; cin >> x;
            if (x == '1') a[i] |= 1ll << j;
        }
    }
    shuffle(all(a), rng);
    int cnt = min(40, n);
    pair<ll, ll> answer = {0, 0};
    range(c, cnt) {
        ll mask = a[c];
        vector<ll> bts;
        for(ll j = 0; j < m; ++j) {
            if (mask & (1ll << j)) bts.push_back(1ll << j);
        }
        int k = bts.size();
        if (k == 0) continue;
        vector<int> cnt(1 << k);
        range(i, n) {
            int mask2 = 0;
            range(j, k) {
                if ((a[i] & bts[j]) == 0) mask2 ^= 1 << j;
            }
            cnt[mask2]++;
        }
        range(i, k) range(mask2, 1 << k) {
            if (mask2 & (1 << i)) cnt[mask2] += cnt[mask2 ^ (1 << i)];
        }
        int al = 1 << k;
        al--;
        pair<int, int> answer2 = {0, 0};
        range(i, 1 << k) {
            if (cnt[i] * 2 < n) continue;
            int msk = al ^ i;
            answer2 = max(answer2, {__builtin_popcount(msk), msk});
        }
        if (answer2.first <= answer.first) continue;
        ll mask2 = 0;
        range(j, k) {
            if (answer2.second & (1 << j)) {
                mask2 ^= bts[j];
            }
        }
        answer.first = answer2.first;
        answer.second = mask2;
    }
    for(ll j = 0; j < m; ++j) {
        if ((1ll << j) & answer.second) {
            cout << '1';
        } else {
            cout << '0';
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
//    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}