#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, t) for (int i = s; i < t; i++)
#define per(i, s, t) for (int i = s; i >= t; i--)
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

const int INF = (int) (1e9 + 1e6 + 123);
const ll LINF = (ll) (1e18 + 1e9 + 123);

template<typename A, typename B> bool mini(A& x, const B& y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<typename A, typename B> bool maxi(A& x, const B& y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

bool test(int mask, int bit) {
    return mask & (1 << bit);
}

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(12);
    run();
    return 0;
}

const int L = 30;

int solve(int a, int b, int n) {
    if (a == 0 && b == 0) {
        return 0;
    } else if (a == 0 && b == 1) {
        int t = n % 3;
        if (t == 0) {
            return 0;
        } else {
            return 1;
        }
    } else if (a == 1 && b == 0) {
        if (n == 0) {
            return 1;
        } else if (n == 1) {
            return 0;
        }
        int t = (n - 2) % 3;
        if (t == 0 || t == 1) {
            return 1;
        } else {
            return 0;
        }
    } else {
        int t = n % 3;
        if (t == 0 || t == 1) {
            return 1;
        } else {
            return 0;
        }
    }
}

void run() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, n;
        cin >> a >> b >> n;
        int res = 0;
        for (int i = 0; i < L; i++) {
            res |= (1 << i) * solve(test(a, i), test(b, i), n);
        }
        cout << res << "\n";
    }
}