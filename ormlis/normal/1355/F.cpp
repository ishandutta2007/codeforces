#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 4e18;
const int INFi = 2e9;
const int maxN = 3e5 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

ll req(ll Q) {
    cout << "? " << Q << endl;
    ll res;
    cin >> res;
    return res;
}

vector<int> primes;
int min_prime[maxN];

void init() {
    for (int i = 2; i < maxN; ++i) {
        if (min_prime[i] == 0) {
            primes.push_back(i);
            min_prime[i] = i;
        }
        for (auto &p: primes) {
            if (p > min_prime[i] || 1ll * i * p >= maxN) break;
            min_prime[i * p] = p;
        }
    }
}

void solve() {
    map<int, int> checked;

    map<int, pair<int, int>> need_to_check;

    for (auto &p: primes) need_to_check[p] = {1, p};

    range(_, 22) {
        ll current = 1;
        vector<int> del;
        vector<int> c;
        for(auto &a: need_to_check) {
            if (a.second.second > 1e9) {
                del.push_back(a.first);
                continue;
            }
            if (current > 1e18 / a.second.second) continue;
            current *= a.second.second;
            c.push_back(a.first);
        }
        ll g = req(current);
        for(auto &x: c) {
            if (g % need_to_check[x].second == 0) {
                checked[x] = need_to_check[x].first;
                if (need_to_check[x].second > 1e9 / x) {
                    del.push_back(x);
                    continue;
                }
                need_to_check[x].second *= x;
                need_to_check[x].first++;
            } else {
                del.push_back(x);
            }
        }
        for(auto &x: del) need_to_check.erase(x);
    }
    int ans = 1;
    for(auto p: checked) {
        ans *= (p.second + 1);
    }
    cout << "! " << ans + max(ans, 7) << endl;
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    init();
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}