#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


typedef long long ll;
typedef long double ld;
using namespace std;

// using namespace __gnu_pbds;

const ll INF = 1e18 + 5;
const int INFi = 2e9;
const int maxN = 2e6 + 1000;
const int md2 = 998244353;
const int md = 1e9 + 7;


struct dsu {
    vector<int> dsu;
    int n;

    int get_dsu(int a) {
        if (dsu[a] == a) return a;
        return dsu[a] = get_dsu(dsu[a]);
    }

    void build(int k) {
        n = k;
        dsu.resize(n);
        range(i, n)dsu[i] = i;
    }

    bool unio(int a, int b) {
        a = get_dsu(a), b = get_dsu(b);
        if (rand() % 2) {
            swap(a, b);
        }
        dsu[a] = b;
        return a == b;
    }
};

void solve() {
    int n;
    cin >> n;
    dsu d;
    d.build(n * 4 + 100);
    vector<string> a(n);
    range(i, n) cin >> a[i];
    vector<string> b(n);
    range(i, n) {
        cin >> b[i];
    }
    range(i, n) {
        range(j, n) {
            if (b[i][j] == a[i][j]) {
                d.unio(i, n + j);
                d.unio(n * 2 + i, n * 3 + j);
            } else {
                d.unio(n * 2 + i, n + j);
                d.unio(i, n * 3 + j);
            }
        }
    }
    range(i, n) {
        if (d.get_dsu(i) == d.get_dsu(n * 2 + i)) {
            cout << "NO\n";
            return;
        }
        if (d.get_dsu(n + i) == d.get_dsu(n * 3 + i)) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}