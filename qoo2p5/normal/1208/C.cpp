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

const int N = 2005;

int n;
int a[N][N];

int c = 0;

void paint(int x, int y, int w, int h) {
    if (w == 0 || h == 0) {
        return;
    }
    int t = 1;
    while (2 * t <= min(w, h)) {
        t *= 2;
    }
    if (t == w && t == h) {
        rep(i, 0, w) {
            rep(j, 0, h) {
                a[x + i][y + j] = c++;
            }
        }
        return;
    }
    paint(x, y, t, t);
    paint(x + t, y, w - t, t);
    paint(x, y + t, t, h - t);
    paint(x + t, y + t, w - t, h - t);
}

void run() {
    cin >> n;
    paint(0, 0, n, n);

    int x = 0;
    rep(i, 0, n) {
        x ^= a[0][i];
    }
    rep(i, 0, n) {
        int y = 0;
        rep(j, 0, n) {
            y ^= a[i][j];
        }
        assert(x == y);
        y = 0;
        rep(j, 0, n) {
            y ^= a[j][i];
        }
        assert(x == y);
    }

    rep(i, 0, n) {
        rep(j, 0, n) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}