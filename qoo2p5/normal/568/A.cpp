#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-8
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)

#define MAXN (int) 2e6
ll p, q;
int d[11];

inline bool is_palindrom(int x) {
    int l = 0;
    while (x != 0) {
        d[l] = x % 10;
        x /= 10;
        l++;
    }

    for (int i = 0; i < l; i++) {
        if (d[i] != d[l - i - 1]) {
            return false;
        }
    }

    return true;
}

bool is_nprime[MAXN];

int main() {
    ios::sync_with_stdio(false);
#ifndef NDEBUG
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

    cin >> p >> q;

    int pals = 0;
    int ans = 0;
    int cnt = 0;
    is_nprime[1] = true;

    for (int i = 1; i < (int) 2e6; i++) {
        if (is_palindrom(i)) {
            pals++;
        }

        if (!is_nprime[i]) {
            cnt++;
            for (int j = i; j < MAXN; j += i) {
                is_nprime[j] = true;
            }
        }

        if (cnt * q <= p * pals) {
            ans = i;
        }
    }

    cout << ans << "\n";

    return 0;
}