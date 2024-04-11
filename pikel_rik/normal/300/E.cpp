#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int A = 1e7;

ll cnt[A + 1];
vector<int> primes;
bitset<A + 1> prime;

void sieve() {
    for (int i = 2; i <= A; i++)
        prime[i] = true;

    for (int i = 2; i * i <= A; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= A; j += i) {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= A; i++) {
        if (prime[i])
            primes.push_back(i);
    }
}

bool f(ll x) {
    bool ok = true;
    for (int p : primes) {
        ll c = 0;

        ll pow = p;
        ld actual = p;

        while (actual <= x) {
            c += x / pow;
            pow *= p;
            actual *= p;
        }

        ok &= c >= cnt[p];
    }
    return ok;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cnt[1] = n;
    while (n--) {
        int x;
        cin >> x;
        if (x != A)
            cnt[x + 1]--;
    }

    for (int i = 2; i <= A; i++) {
        cnt[i] += cnt[i - 1];
    }

    sieve();

    for (int p : primes) {
        ll c = 0;
        for (ll i = p; i <= A; i *= p) {
            for (int j = i; j <= A; j += i) {
                c += cnt[j];
            }
        }
        cnt[p] = c;
    }

    ll lo = 1, hi = (ll)1e15;

    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (f(mid))
            hi = mid;
        else lo = mid + 1;
    }

    cout << lo << "\n";
    return 0;
}