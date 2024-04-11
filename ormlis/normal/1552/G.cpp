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

const int INFi = 2e9 + 5;
const int maxN = 2e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

ll srt(ll mask, ll submask, ll n) {
    ll cnt = __builtin_popcountll(mask & submask);
    for (ll i = n - 1; i >= 0; --i) {
        if (submask & (1ll << i)) {
            if (cnt) {
                mask |= (1ll << i);
                cnt--;
            } else {
                mask &= ~(1ll << i);
            }
        }
    }
    return mask;
}

void solve() {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << "ACCEPTED\n";
        return;
    }
    int k;
    cin >> k;
    ll was = 0;
    vector<ll> can = {0};
    range(_, k) {
        ll cur = 0;
        int q;
        cin >> q;
        range(__, q) {
            ll j;
            cin >> j;
            j--;
            cur |= (1ll << j);
        }
        vector<ll> nxt;
        ll new_bits = (cur ^ was) & cur;
        ll cnt = __builtin_popcountll(new_bits);
        vector<ll> to(cnt + 1);
        {
            ll j = 1;
            for (ll i = 0; i < n; ++i) {
                if ((1ll << i) & new_bits) {
                    to[j] = to[j - 1] | (1ll << i);
                    j++;
                }
            }
        }
        range(nw, cnt + 1) {
            for (auto &mask : can) {
                ll mask2 = mask | to[nw];
                nxt.push_back(srt(mask2, cur, n));
            }
        }
        sort(all(nxt));
        nxt.resize(unique(all(nxt)) - nxt.begin());
        swap(nxt, can);
        was |= cur;
    }
    if (can.size() != n + 1) {
        cout << "REJECTED\n";
        return;
    }
    bool ok = (can[0] == 0);
    range(i, n) {
        ok &= (can[i + 1] == (can[i] | (1ll << (n - 1 - i))));
    }
    cout << (ok ? "ACCEPTED\n" : "REJECTED\n");
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