#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <numeric>
#include <iomanip>
#include <string>
#include <chrono>
#include <complex>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;

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



ll calcmid(ll x) {
    return bpw(2, x + 1);
}

void solve() { //REMEMBER ALL ZEROS
    //N == 1!!!
    //ZEROS IN MIDDLE OF LAST ITERATION
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> p(n);
    foru(i, 0, n)cin >> a[i], p[i] = (i ? p[i - 1] : 0) + a[i];
    set<pll> pre;
    foru(i, 0, n)pre.insert({ p[i],i });
    ll tot = 1;
    int lptr = 0, rptr = n - 1, zl=0,zr=0;
    while (lptr < n && a[lptr] == 0) {
        lptr++;
        zl++;
    }
    while (rptr >= 0 && a[rptr] == 0) {
        rptr--;
        zr++;
    }
    if (lptr == n) {
        cout << bpw(2, n - 1) << '\n';
        return;
    }
    ll tomul = 1;
    int topart = min(zl, zr);
    for (int part = 1; part <= topart; part++) {
        iadd(tomul, mult(chs(zl, part), chs(zr, part)));
    }
    imult(tot, tomul);
    while (true) { //CHOOSE RIGHTS INSTEAD OF LEFTS
        //searching for equal range
        ll lsum = 0, rsum = 0;
        while (lptr < n && rptr >= 0) {
            if (lsum <= rsum)lsum += a[lptr++];
            else rsum += a[rptr--];
            if (lsum == rsum) {
                lptr--;
                rptr++;
                break;
            }
        }
        if (lptr >= rptr)break; //no more equal ranges, stop TODO
        zl = 0;
        zr = 0;
        for (int li = lptr + 1; li < n; li++) {
            if (a[li] == 0)zl++;
            else break;
        }
        for (int ri = rptr - 1; ri > 0; ri--) {
            if (a[ri] == 0)zr++;
            else break;
        }
        if (lptr + zl + 1 == rptr) {
            imult(tot, calcmid(zl));
            break;
        }
        lptr += (zl + 1);
        rptr -= (zr + 1);
        int topart = min(zl, zr) + 1;
        ll tomul = 1;
        for (int part = 1; part <= topart; part++) {
            ll now = mult(chs(zl + 1, part), chs(zr + 1, part));
            iadd(tomul, now);
        }
        imult(tot, tomul);
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