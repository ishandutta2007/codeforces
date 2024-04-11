#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define f0r(a, b) for (int i = (a); i < (b); ++i)
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}


void solve(int test) {
    ll a, b, n;
    cin >> n;
    cin >> a >> b;
    ll N = n;
    int da, db;
    {
        str aa, bb;
        cin >> aa >> bb;
        if (aa[0] == 'r') da = 1;
        else da = -1;
        if (bb[0] == 'r') db = 1;
        else db = -1;
    }
    vector<ll> have;
    int iters = 100;
    while (n > 1) {
        iters--;
        if (iters == 0) break;
        if (a == 0) da = 1;
        if (a == n - 1) da = -1;
        if (b == 0) db = 1;
        if (b == n - 1) db = -1;
        if (a == b) {
            if (a == 0) {
                cout << N - 1 << '\n';
                return;
            }
            if (a == n - 1) {
                cout << "0\n";
                return;
            }
            have.push_back(a);
            // cout << a << '\n';
            a += min(da, 0);
            b += min(db, 0);
            n--;
            continue;
        }
        if ((da == db) || (a < b && da == -1) || (a > b && db == -1)) {
            ll ops = n;
            if (da == -1) ops = min(ops, a);
            else ops = min(ops, n - 1 - a);
            if (db == -1) ops = min(ops, b);
            else ops = min(ops, n - 1 - b);
            a += da * ops;
            b += db * ops;
            continue;
        }
        if (a + 1 == b) {
            a++;
            swap(da, db);
            continue;
        }
        if (a - 1 == b) {
            a--;
            swap(da, db);
            continue;
        }
        ll need = abs(a - b) / 2;
        a += da * need;
        b += db * need;
    }
    assert(have[0] - have[2] == 1);
    assert(have[1] - have[3] == 1);
    ll t = N - 1;
    // (t - 1 - 2 * k) == have[1] - k
    // t == have[0] + k
    ll k = t - have[0];
    ll k2 = t - 1 - have[1];
    ll resN = min(k * 2, k2 * 2 + 1);
    ll res0 = min(have[0] * 2, have[1] * 2 + 1);
    if (res0 < resN) {
        cout << N - 1 << '\n';
    } else {
        cout << "0\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve(i);
    }
    return 0;
}