#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

const ll mod = 998244353;

void imult(ll & lhs, const ll & rhs) {
    lhs = (lhs * rhs) % mod;
}

void iadd(ll & lhs, const ll & rhs) {
    lhs = (lhs + rhs) % mod;
}

void isubt(ll & lhs, const ll & rhs) {
    ll ret = (lhs - rhs) % mod;
    lhs = ret + (ret < 0 ? mod : 0);
}

ll bpw(const ll & lhs, const ll & rhs) {
    if (rhs == 0)return 1;
    ll ret = bpw(lhs, rhs >> 1);
    imult(ret, ret);
    if (rhs & 1) imult(ret, lhs);
    return ret;
}

ll inv(const ll & x) {
    return bpw(x, mod - 2);
}

ll mult(const ll & lhs, const ll & rhs) {
    return (lhs * rhs) % mod;
}

ll add(const ll & lhs, const ll & rhs) {
    return (lhs + rhs) % mod;
}

ll subt(const ll & lhs, const ll & rhs) {
    ll ret = (lhs - rhs) % mod;
    return ret + (ret < 0 ? mod : 0);
}

ll divv(const ll & lhs, const ll & rhs) {
    return mult(lhs, inv(rhs));
}

const int sz = 5e5 + 5;
ll f[sz], finv[sz];

void initf() {
    f[0] = 1;
    foru(i, 1, sz)f[i] = mult(i, f[i - 1]);
    finv[sz - 1] = bpw(f[sz - 1], mod - 2);
    ford(i, sz - 2, 0)finv[i] = mult(finv[i + 1], i + 1);
}

ll chs(int n, int k) {
    if (n < k)return 0;
    else if (n < 0)return 0;
    return mult(f[n], mult(finv[k], finv[n - k]));
}

void solve() {
    int n;
    string st;
    cin >> n >> st;
    string s = "";
    int cur = 0;
    for (char c : st) {
        if (c == '1')s.push_back(c), cur++;
        else {
            if (cur & 1)s.pop_back();
            cur = 0;
            s.push_back('0');
        }
    }
    if (cur & 1)s.pop_back();
    n = s.length();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1')cnt++, i++;
    }
    int zsm = n - 2 * cnt;
    int zcnt = cnt + 1;
    ll ans = chs(zsm + zcnt - 1, zcnt - 1);
    cout << ans << '\n';
}

int main() {
    fast;
    initf();
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}