/**
  *  Team Eat Less - Drink More
  */
#ifdef LOCAL
//#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>

#define szof(a) ((int)(a).size())
#define bend(a) a.begin(), a.end()
#define ff first
#define ss second
#define puba push_back

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pii;

int millis() { static auto start = chrono::system_clock::now(); return 1e3 * chrono::duration<double>(chrono::system_clock::now() - start).count(); }

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);

    int l = 0, r = n - k;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        ll tmp = (ll) (mid - 1) / 2 * (k - 2);
        if (tmp >= n - k - mid) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r + 1 << "\n";
    vector<int> order;
    for (int i = 0; i < r + 2; ++i) {
        order.puba(i);
    }
    for (int i = 0; i < szof(order) - 1; ++i) {
        cout << order[i] + 1 << " " << order[i + 1] + 1 << "\n";
    }
    int val = (r - 1) / 2;
    int c = n - (k - 2);
    for (int i = r + 2; i < n - (k - 2); i += val) {
        int prev = order[szof(order) / 2];
        for (int j = 0; j < val && i + j < n - (k - 2); ++j) {
            cout << prev + 1 << " " << i + j + 1 << "\n";
            prev = i + j;
        }
        cout << prev + 1 << " " << c + 1 << "\n";
        ++c;
    }
    while (c < n) {
        cout << order[szof(order) / 2] + 1 << " " << c + 1 << "\n";
        ++c;
    }
}

int main() {
    millis();
    cout << setprecision(15) << fixed;
#ifdef LOCAL
    cerr << setprecision(4) << fixed;
#endif
    int tests = 1;
    for (int test = 1; test <= tests; ++test) {
        solve();
    }
#ifdef LOCAL
    cerr << "time: " << millis() << " ms\n";
#endif
}