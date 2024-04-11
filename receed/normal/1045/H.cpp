#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring>
#include <cassert>
#include <bitset>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int N = 200002, MOD = 1e9 + 7;
ll f[N];
int c00, c01, c10, c11;

ll pw(ll x, ll k) {
    if (!k)
        return 1;
    if (k % 2)
        return pw(x, k - 1) * x % MOD;
    return pw(x * x % MOD, k / 2);
}

ll c(ll n, ll k) {
    return f[n] * pw(f[k] * f[n - k] % MOD, MOD - 2) % MOD;
}

ll cnt(int t00, int t01, int t10, int t11) {
    if (t00 < 0 || t01 < 0 || t10 < 0 || t11 < 0 || t01 != t10 && t01 != t10 + 1)
        return 0;
    if (t01 == 0) {
        if (t11)
            return 0;
        return 1;
    }
    return c(t00 + t10, t00) * c(t11 + t01 - 1, t11) % MOD;
}

ll solve(string s) {
    int t00 = c00, t01 = c01, t10 = c10, t11 = c11, sm = c00 + c01 + c10 + c11;
    if (s.size() < sm + 1)
        return 0;
    if (s.size() > sm + 1)
        return cnt(t11, t10, t01, t00);
    ll ans = 0;
    for (int i = 0; i + 1 < s.size(); i++) {
        if (s[i] == '0') {
            if (s[i + 1] == '0')
                t00--;
            else {
                ans = (ans + cnt(t00 - 1, t01, t10, t11)) % MOD;
                t01--;
            }
        }
        else {
            if (s[i + 1] == '0')
                t10--;
            else {
                ans = (ans + cnt(t00, t01, t10 - 1, t11)) % MOD;
                t11--;
            }
        }
    }
    ans = (ans + cnt(t00, t01, t10, t11)) % MOD;
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#else
    //freopen("wikipidia.in", "r", stdin); 
    //freopen("wikipidia.out", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string a, b;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] == '0')
            a[i] = '1';
        else {
            a[i] = '0';
            break;
        }
    }
    if (a[0] == '0')
        a.erase(a.begin());
    cin >> c00 >> c01 >> c10 >> c11;
    f[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = f[i - 1] * i % MOD;
    cout << (solve(b) + MOD - solve(a)) % MOD << '\n';
}