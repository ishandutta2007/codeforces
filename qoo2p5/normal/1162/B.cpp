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

void run() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> a[i][j];
        }
    }
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> b[i][j];
        }
    }

    auto no = [] () {
        cout << "Impossible\n";
        exit(0);
    };

    rep(i, 0, n) {
        rep(j, 0, m) {
            if (a[i][j] > b[i][j]) {
                swap(a[i][j], b[i][j]);
            }
            if (i > 0) {
                if (a[i - 1][j] >= a[i][j]) no();
                if (b[i - 1][j] >= b[i][j]) no();
            }
            if (j > 0) {
                if (a[i][j - 1] >= a[i][j]) no();
                if (b[i][j - 1] >= b[i][j]) no();
            }
        }
    }

    cout << "Possible\n";
}