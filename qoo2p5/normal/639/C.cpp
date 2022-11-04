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
const int L = 33;

int n;
ll k;
ll a[N];
bool flag;
ll res[N];

void add(ll x, bool neg, int shift) {
     for (int j = 0; j < L; j++) {
         if (x & (1LL << j)) {
             res[shift + j] += (neg ? -1 : 1);
         }
     }
}

void work() {
    for (int i = 0; i < N - 1; i++) {
        if (res[i] < 0) {
            ll q = (abs(res[i]) + 1) / 2;
            res[i] += 2 * q;
            res[i + 1] -= q;
        } else if (res[i] > 0) {
            ll q = res[i] / 2;
            res[i] -= 2 * q;
            res[i + 1] += q;
        }
    }
    
    if (res[N - 1] == -1) {
        res[N - 1] = 0;
        for (int i = 0; i < N - 1; i++) {
            res[i] = !res[i];
        }
        res[0]++;
        flag = true;
        work();
    }
}

int ans = 0;

void check(ll x, int pos, bool not_null) {
    ll c = (flag ? a[pos] + x : a[pos] - x);
    if (abs(c) <= k && (!not_null || c != 0)) {
        ans++;
    }
}

void run() {
     cin >> n >> k;
     for (int i = 0; i < n + 1; i++) {
         cin >> a[i];
         bool neg = (a[i] < 0);
         ll x = abs(a[i]);
         add(x, neg, i);
     }
     
     work();
     for (int i = 0; i < N; i++) {
         assert(0 <= res[i] && res[i] <= 1);
     }
     
     int left = 0;
     int right = N - 1;
     while (!res[left]) {
         left++;
     }
     while (!res[right]) {
         right--;
     }
     int len = right - left + 1;
     
     if (len >= L) {
         cout << "0\n";
         return;
     }
     
     ll cur = 0;
     for (int i = right; i >= left; i--) {
         cur = cur * 2 + res[i];
     }
     
     for (int i = left; i >= 0; i--) {
         if (i <= n) check(cur, i, i == n);
         
         if (i - 1 >= 0) {
             cur *= 2;
             if (cur > 2 * k) {
                 break;
             }
         }
     }
     
     cout << ans << "\n";
}