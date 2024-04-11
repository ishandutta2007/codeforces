#include <bits/stdc++.h>

using namespace std;

const int N = 510;

const int MOD = 998244353;

inline int add(int u, int v) {
    u += v;
    if (u >= MOD) {
        u -= MOD;
    }
    return u;
}

inline int sub(int u, int v) {
    u -= v;
    if (u < 0) {
        u += MOD;
    }
    return u;
}

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

inline int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) {
            res = mul(res, u);
        }
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}

inline int inv(int u) {
    return power(u, MOD - 2);
}

int n;
long long a[N];
map<long long, int> divs;
map<long long, int> alone;

long long my_sqrt(long long u) {
    long long x = sqrt(u);
    while (x * x < u) x++;
    while (x * x > u) x--;
    return x;
}

long long my_cbrt(long long u) {
    long long x = cbrt(u);
    while (x * x * x < u) x++;
    while (x * x * x > u) x--;
    return x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> b;
    for (int i = 1; i <= n; i++) {
        long long foo = my_sqrt((long long)my_sqrt(a[i]));
        if (foo * foo * foo * foo == a[i]) {
            divs[foo] += 4;
            continue;
        }
        foo = my_cbrt(a[i]);
        if (foo * foo * foo == a[i]) {
            divs[foo] += 3;
            continue;
        }
        foo = my_sqrt(a[i]);
        if (foo * foo == a[i]) {
            divs[foo] += 2;
            continue;
        }
        b.push_back(i);
    }
    for (int id = 0; id < b.size(); id++) {
        int i = b[id];
        int f = 0;
        for (auto u : divs) {
            if (a[i] % u.first == 0) {
                divs[u.first]++;
                divs[a[i] / u.first]++;
                f = 1;
                break;
            }
        }
        if (f) {
            continue;
        }
        for (int j = id + 1; j < b.size(); j++) {
            long long foo = __gcd(a[i], a[b[j]]);
            if (foo == 1 || foo == a[i]) {
                continue;
            }
            divs[foo]++;
            divs[a[i] / foo]++;
            f = 1;
            break;
        }
        if (f) {
            continue;
        }
        alone[a[i]]++;
    }
    int res = 1;
    for (auto u : alone) {
        int foo = mul(u.second + 1, u.second + 1);
        res = mul(res, foo);
    }
    for (auto u : divs) {
        res = mul(res, u.second + 1);
    }
    cout << res << endl;
    cout.flush();
    return 0;
}