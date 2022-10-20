#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int M = 2000010;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
long long a[N];
long long aMin;
bool p[M];
vector<int> primes;
set<long long> used;
long long res;
long long val[N * 2];

void solve(long long u) {
    if (used.count(u)) return;
    used.insert(u);
    long long cur = 0;
    for (int i = 1; i <= n; i++) {
        long long now = a[i] % u;
        if (a[i] == now) cur += u - now;
        else cur += min(now, u - now);
        if (cur >= res) break;
    }
    res = min(res, cur);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;   
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    shuffle(a + 1, a + n + 1, rng);
    aMin = *min_element(a + 1, a + n + 1);
    res = n;
    for (int i = 2; i < M; i++) {
        if (!p[i]) {
            primes.push_back(i);
            for (int j = i + i; j < M; j += i) p[j] = 1;
        }
    }
    for (int u : primes) {
        solve(u);
    }
    long long l = max(1ll, aMin - res);
    long long r = aMin + res;
    if (l <= r) {
        int len = r - l + 1;
        for (int i = 0; i < len; i++) val[i] = l + i;
        for (int u : primes) {
            long long firstVal = 1ll * ((l - 1) / u + 1) * u;
            long long cur = firstVal - l;
            while (firstVal <= r) {
                while (val[cur] % u == 0) {
                    val[cur] /= u;
                }
                cur += u;
                firstVal += u;
            }
        }
        for (int i = 0; i < len; i++) {
            if (val[i] > 1) solve(val[i]);
        }
    }
    cout << res << endl;
    return 0;
}