#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 1e6 + 123;
const ll LINF = (ll) 1e18 + 1e9 + 123;

template<typename A, typename B> bool mini(A &x, const B &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<typename A, typename B> bool maxi(A &x, const B &y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

// Solution

const int N = (int) 3e5 + 123;
const int L = 7;

int n;
bool has_or[N];
bool has[N];
int cool[N];
bool is_np[N];
vector<int> primes[N];
vector<int> overmasks[L][1 << L];
int cnt[N];

bool test(int mask, int bit) {
    return mask & (1 << bit);
}

int dp[1 << L];

void run() {
    cin >> n;
    int g = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        has_or[x] = true;
        g = __gcd(g, x);
    }
    if (g != 1) {
        cout << "-1\n";
        return;
    }
    if (has_or[1]) {
        cout << "1\n";
        return;
    }

    for (int len = 1; len < L; len++) {
        for (int mask = 0; mask < (1 << len); mask++) {
            for (int i = 0; i < (1 << len); i++) {
                if ((i & mask) == mask && i != mask) {
                   overmasks[len][mask].push_back(i);
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cool[i] = 1;
    }
    for (int i = 2; i < N; i++) {
        if (is_np[i]) {
            continue;
        }
        cool[i] = i;
        primes[i].push_back(i);
        for (int j = i + i; j < N; j += i) {
            is_np[j] = true;
            cool[j] *= i;
            primes[j].push_back(i);
        }
    }

    for (int i = 1; i < N; i++) {
        has[cool[i]] |= has_or[i];
        assert((int) primes[i].size() < L);
    }
    for (int i = 1; i < N; i++) {
        if (cool[i] != i || !has[i]) {
            continue;
        }

        int k = (int) primes[i].size();
        for (int mask = 0; mask < (1 << k); mask++) {
            int p = 1;
            for (int bit = 0; bit < k; bit++) {
                if (test(mask, bit)) {
                    p *= primes[i][bit];
                }
            }
            cnt[p]++;
        }
    }

    vector<int> var;
    int ans = INF;
    for (int i = 1; i < N; i++) {
        if (cool[i] != i || !has[i]) {
            continue;
        }

        memset(dp, 0, sizeof dp);
        int k = (int) primes[i].size();
        for (int mask = 0; mask < (1 << k); mask++) {
            dp[mask] = 0;
            int p = 1;
            for (int bit = 0; bit < k; bit++) {
                if (test(mask, bit)) {
                    p *= primes[i][bit];
                }
            }
            dp[mask] = cnt[p];
        }
        var.clear();
        for (int mask = (1 << k) - 1; mask >= 0; mask--) {
            for (int over : overmasks[k][mask]) {
                dp[mask] -= dp[over];
            }
            if (dp[mask]) {
                var.push_back(mask);
            }
        }

        for (int mask = 0; mask < (1 << k); mask++) {
            dp[mask] = INF;
        }
        dp[(1 << k) - 1] = 1;
        for (int meow : var) {
            for (int mask = 0; mask < (1 << k); mask++) {
                mini(dp[mask & meow], dp[mask] + 1);
            }
        }
        mini(ans, dp[0]);
    }
    cout << ans << "\n";
}