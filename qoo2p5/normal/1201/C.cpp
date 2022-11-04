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

const int N = (int) (2e5 + 123);

int n, k;
int a[N];

void run() {
    cin >> n >> k;
    rep(i, 0, n) cin >> a[i];
    sort(a, a + n);
    int ans = a[n / 2];
    int ptr = n / 2;
    while (k > 0) {
        while (ptr + 1 < n && a[ptr + 1] == ans) {
            ptr++;
        }
        int cost = (ptr - n / 2 + 1);
        if (cost > k) {
            break;
        }
        int max_steps = (ptr == n - 1 ? INF : a[ptr + 1] - a[ptr]);
        int can_steps = k / cost;
        int steps = min(max_steps, can_steps);
        k -= cost * steps;
        ans += steps;
    }
    cout << ans << "\n";
}