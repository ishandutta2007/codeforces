#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e5 + 5;
const int A = 5e5;

int mu[A + 1], spf[A + 1];
vector<int> divisors[A + 1];

void compDivisors() {
    for (int i = 1; i <= A; i++) {
        for (int j = i; j <= A; j += i) {
            divisors[j].push_back(i);
        }
        if (i == 1) {
            mu[i] = 1;
        } else {
            spf[i] = divisors[i][1];
            if ((i / spf[i]) % spf[i] == 0) {
                mu[i] = 0;
            } else {
                mu[i] = -mu[i / spf[i]];
            }
        }
    }
}

int n, q, a[N], cnt[A + 1];
bool removed[N];

void add(int x) {
    for (int d : divisors[x]) {
        cnt[d]++;
    }
}

void remove(int x) {
    for (int d : divisors[x]) {
        cnt[d]--;
    }
}

ll count(int x) {
    ll c = 0;
    for (int d : divisors[x]) {
        c += mu[d] * cnt[d];
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    compDivisors();

    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    memset(removed, true, sizeof(removed));

    while (q--) {
        int i;
        cin >> i; --i;

        if (removed[i]) {
            ans += count(a[i]);
            add(a[i]);
        } else {
            remove(a[i]);
            ans -= count(a[i]);
        }
        removed[i] = !removed[i];
        cout << ans << '\n';
    }
    return 0;
}