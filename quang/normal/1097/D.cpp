#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int MOD = 1000000007;

inline int add(int u, int v)  {
    u += v;
    if (u >= MOD) u -= MOD;
    return u;
}

inline int sub(int u, int v) {
    u -= v;
    if (u < 0) u += MOD;
    return u;
}

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

inline int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) res = mul(res, u);
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}

inline int inv(int u) {
    return power(u, MOD - 2);
}

long long n;
int k;
int invC[100];

int get(pair<long long, int> u) {
    u.first %= MOD;
    vector<int> now(u.second + 1);
    int cur = 1;
    for (int i = 0; i < now.size(); i++) {
        now[i] = cur;
        cur = mul(cur, u.first);
    }
    for (int i = 1; i <= k; i++) {
        vector<int> pref(u.second + 1);
        pref[0] = now[0];
        for (int j = 1; j < pref.size(); j++) {
            pref[j] = add(pref[j - 1], now[j]);
        }
        for (int j = 0; j < now.size(); j++) {
            now[j] = mul(pref[j], invC[j + 1]);
        }
    }
    return now.back();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i < 100; i++) {
        invC[i] = inv(i);
    }
    cin >> n >> k;
    vector<pair<long long, int> > divs;
    long long u = n;
    for (long long i = 2; i * i <= u; i++) {
        if (u % i == 0) {
            divs.push_back({i, 0});
            while (u % i == 0) {
                u /= i;
                divs.back().second++;
            }
        }
    }
    if (u != 1) {
        divs.push_back({u, 1});
    }
    int res = 1;
    for (auto v : divs) {
        res = mul(res, get(v));
    }
    cout << res << endl;
    return 0;
}