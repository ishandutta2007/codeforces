#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 4e18;
const int INFi = 2e9;
const int maxN = 2e5 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

int min_prime[maxN];
vector<int> primes;

void gg() {
    min_prime[1] = 1;
    for (int i = 2; i < maxN; ++i) {
        if (min_prime[i] == 0) {
            min_prime[i] = i;
            primes.push_back(i);
        }
        for (auto &p: primes) {
            if (p > min_prime[i] || 1ll * p * i >= maxN) break;
            min_prime[p * i] = p;
        }
    }
}

void solve() {
    ll x = 1;
    int n;
    cin >> n;
    gg();
    map<int, int> mp;
    range(i, (int)primes.size()) mp[primes[i]] = i;
    vector<pair<int, int>> res(primes.size(), {INFi, INFi});
    vector<int> cnt(primes.size(), 0);
    range(i, n) {
        int a;
        cin >> a;
        range(j, (int) primes.size()) {
            if (a == 1) break;
            if (min_prime[a] == a) {
                j = mp[a];
            }
            int cur = 0;
            while (a % primes[j] == 0) {
                cur++;
                a /= primes[j];
            }
            if (cur > 0) cnt[j]++;
            else continue;
            if (res[j].first > cur) {
                res[j].second = res[j].first;
                res[j].first = cur;
            } else if (res[j].second > cur) {
                res[j].second = cur;
            }
        }
    }
    range(i, (int) primes.size()) {
        if (cnt[i] < n - 1) continue;
        if (cnt[i] == n - 1) {
            range(_, res[i].first) x *= primes[i];
            continue;
        }
        range(_, res[i].second) x *= primes[i];
    }
    cout << x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}