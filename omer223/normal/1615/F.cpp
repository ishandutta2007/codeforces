
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

const ll mod = 1e9 + 7;


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

ll foo(int nL, int qnL, int mL, int qmL) {
    int d = mL - nL;
    if (qnL < d || qmL < -d)return 0;
    else return mult(f[qnL + qmL], mult(finv[qnL - d], finv[qmL + d]));
}

void solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    foru(i, 0, n) {
        if (s[i] != '?')s[i] = (s[i] == '0') ^ (i % 2) + '0';
        if (t[i] != '?')t[i] = (t[i] == '0') ^ (i % 2) + '0';
    }
    ll tot = 0;
    int nL = 0, mL = 0, qnL = 0, qmL = 0;
    int nR = 0, mR = 0, qnR = 0, qmR = 0;
    foru(i, 0, n) {
        if (s[i] == '?')qnR++;
        else if (s[i] == '1')nR++;
        if (t[i] == '?')qmR++;
        else if (t[i] == '1')mR++;
    }
    int tmR = mR, tqmR = qmR;
    foru(i, 0, n) { 
        if (s[i] == '0')continue;
        else if (s[i] == '1')nR--;
        else qnR--;
        foru(j, 0, n) {
            if (t[j] == '0')continue;
            else if (t[j] == '1')mR--;
            else qmR--;
            ll dist = abs(i - j);
            ll toadd = mult(foo(nR, qnR, mR, qmR), foo(nL, qnL, mL, qmL));
            iadd(tot, mult(dist, toadd));
            if (t[j] == '1')mL++;
            else qmL++;
        }
        if (s[i] == '1')nL++;
        else qnL++;
        mL = qmL = 0;
        mR = tmR;
        qmR = tqmR;
    }
    cout << tot << '\n';
}

int main() {
    fast;
    initf();
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}