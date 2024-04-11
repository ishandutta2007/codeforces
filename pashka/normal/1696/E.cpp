#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

#define MOD 1000000007

long sum(long a, long b) { return (a + b) % MOD; }
long mult(long a, long b) { return (a * b) % MOD; }

long power(long a, long b) {
    long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mult(res, a);
        }
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

long inv(long a) {
    return power(a, MOD - 2);
}

vector<long> fact_precalc(1, 1);
vector<long> inv_fact_precalc(1, 1);

void ensure_fact(int n) {
    while (n >= fact_precalc.size()) {
        fact_precalc.push_back(mult(fact_precalc.back(), fact_precalc.size()));
        inv_fact_precalc.push_back(inv(fact_precalc.back()));
    }
}

long fact(int n) {
    ensure_fact(n);
    return fact_precalc[n];
}

long inv_fact(int n) {
    ensure_fact(n);
    return inv_fact_precalc[n];
}

long calc_c(int n, int k) {
    long res = fact(n);
    res = mult(res, inv_fact(k));
    res = mult(res, inv_fact(n - k));
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    long res = 0;
    for (int i = 0; i < n + 1; i++) {
        int x;
        cin >> x;
        if (x > 0)
        res += calc_c(x + i, i + 1);
        res %= MOD;
    }
    cout << res << "\n";
    return 0;
}