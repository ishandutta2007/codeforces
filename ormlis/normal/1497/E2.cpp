#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

typedef long long ll;

using namespace std;
//using namespace __gnu_pbds;

const int INFi = 2e9 + 5;
const int maxN = 1e7 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;

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
            mp[p * i] = p;
        }
    }
}

int get_primes(int x) {
    int result = 1;
    while (x != 1) {
        int d = mp[x];
        if (result % d == 0) result /= d;
        else result *= d;
        x /= d;
    }
    return result;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    range(i, n) {
        cin >> a[i];
        a[i] = get_primes(a[i]);
    }
    vector<int> nxt(n, n);
    vector<int> pr(n, -1);
    map<int, int> last;
    for (int i = n - 1; i >= 0; --i) {
        if (last.count(a[i])) {
            nxt[i] = last[a[i]];
        }
        last[a[i]] = i;
    }
    last.clear();
    range(i, n) {
        if (last.count(a[i])) {
            pr[i] = last[a[i]];
        }
        last[a[i]] = i;
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INFi));
    dp[0][0] = 0;
    vector<int> uk(k + 1, 0);
    vector<int> cnt(k + 1, 0);
    range(i, n) {
        range(j, k + 1) {
            while (uk[j] < n) {
                if (pr[uk[j]] >= i) {
                    if (cnt[j] == j) break;
                    cnt[j]++;
                }
                uk[j]++;
            }
        }
        range(j, k + 1) {
            if (dp[i][j] == INFi) continue;
            for (int e = 0; e + j <= k; ++e) {
                dp[uk[e]][e + j] = min(dp[uk[e]][e + j], dp[i][j] + 1);
            }
        }
        range(j, k + 1) {
            if (nxt[i] < uk[j]) {
                cnt[j]--;
            }
        }
    }
    cout << *min_element(all(dp[n])) << '\n';
}

int main() {
    init();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}