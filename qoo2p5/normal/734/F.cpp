#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;
const ld EPS = (ld) 1e-7;
const int MOD = (int) 1e9 + 7;

#define sz(x) (int) (x).size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) (x).begin(), (x).end()
#define lb(s, t, x) (int) (lower_bound(s, t, x) - s)
#define ub(s, t, x) (int) (upper_bound(s, t, x) - s)

template<typename A, typename B> bool mini(A &x, const B &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<typename A, typename B> bool maxi(A &x, const B &y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

void run();

int main() {
#ifndef LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#endif
    run();
    return 0;
}

// == SOLUTION == //

const int N = (int) 2e5 + 123;
const int L = 50;

int n;
ll a[N], b[N], c[N];
int cnt[L];

bool check() {
    for (int i = 0; i < n; i++) {
        ll res1 = 0;
        ll res2 = 0;
        for (int j = 0; j < L; j++) {
            if (a[i] & (1LL << j)) {
                res1 += n * (1LL << j);
                res2 += cnt[j] * (1LL << j);
            } else {
                res1 += cnt[j] * (1LL << j);
            }
        }
        if (res1 != c[i] || res2 != b[i]) return 0;
    }
    
    return 1;
}

void run() {
    cin >> n;
    ll s = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        s += b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        s += c[i];
    }
    if (s % (2 * n) != 0) {
        cout << "-1\n";
        return;
    }
    s /= (2 * n);
    for (int i = 0; i < n; i++) {
        if ((b[i] + c[i] - s) % n != 0) {
            cout << "-1\n";
            return;
        }
        a[i] = (b[i] + c[i] - s) / n;
        if (a[i] < 0) {
            cout << "-1\n";
            return;
        }
        for (int j = 0; j < L; j++) {
            if (a[i] & (1LL << j)) {
                cnt[j]++;
            }
        }
    }
    if (!check()) {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";   
}