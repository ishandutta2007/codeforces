#define _CRT_SECURE_NO_WARNINGS
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
#include <math.h>
#include <chrono>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

ll n, l, r;
const int N = 1e7;
int lp[N + 1];
ll divby[N + 1];
vector<int> pr;


void sieve() {
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
        }
    }
}

const ld EPS = 1e-12;

inline bool cond(int a1, int a2) {
    ld lhs = (n - 1) * logl(a2), rhs = logl(r) + (n - 2) * logl(a1);
    return lhs <= rhs + EPS;
}

ll cnbnd(int x) {
    int nn = n - 1;
    vector<pii> p;
    ll divby = 1;
    while (x != 1) {
        int crp = lp[x], cr = 0;
        while (x != 1 && lp[x] == crp) {
            x /= lp[x];
            cr++;
        }
        int gpw = cr - cr / nn;
        while (gpw--)divby *= crp;
    }
    return divby;
}

int main() {
    fast;
    sieve();
    cin >> n >> l >> r;
    ll ans = 0;
    if (n == 1) {
        cout << r - l + 1 << '\n';
        return 0;
    }
    else if (n == 2) {
        cout << (r - l + 1) * (r - l) << '\n';
        return 0;
    }
    int mxbnd = l - 1;
    for (int a1 = l; a1 <= r; a1++) {
        while (mxbnd + 1 <= r && cond(a1, mxbnd + 1)) mxbnd++;
        int lbnd = mxbnd;
        ll tmp = cnbnd(a1);
        ll x1 = lbnd / tmp, x2 = a1 / tmp;
        ans += x1 - x2;
    }
    ans <<= 1;
    cout << ans << '\n';
    return 0;
}