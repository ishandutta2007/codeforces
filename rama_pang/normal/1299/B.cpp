#include <bits/stdc++.h>
using namespace std;

// #define TESTCASE

#define all(x) begin(x), end(x)
#define sz(x) x.size()

void solve();
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    #ifdef TESTCASE
    cin >> T;
    #else
    T = 1;
    #endif

    while (T--) {
        solve();
    }
}

#define int long long

void solve() {

    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }
    if (N & 1) {
        cout << "NO\n";
        return;
    }

    map<pair<int, int>, int> mp;

    auto get = [&](pair<int, int> aa, pair<int, int> bb) {
        pair<int, int> a[2];

        a[0] = aa;
        a[1] = bb;

        int u = a[1].first - a[0].first;
        int v = a[1].second - a[0].second;

        if (u * v < 0) {
            if (u > 0) {
                u = -u;
                v = -v;
            }
        } else {
            u = abs(u);
            v = abs(v);
        }
        int g = __gcd(abs(u), abs(v));
        u /= g;
        v /= g;
        return make_pair(u, v);
    };

    auto len = [&](pair<int, int> a1, pair<int, int> a2) {
        int x = (a1.first - a2.first);
        int y = a1.second - a2.second;
        return x * x + y * y;
    };

    for (int i = 0; i < N; i++) {
        bool gradient = (get(A[i], A[(i + 1) % N]) == get(A[(i + N/2) % N], A[(i + N/2 + 1) % N]));
        bool ln = (len(A[i], A[(i + 1) % N]) == len(A[(i + N/2) % N], A[(i + N/2 + 1) % N]));
        if (gradient && ln) continue;
        cout << "NO\n";
        return;
    }

    // for (auto &m : mp) {
    //     if (m.second % 2 == 0) continue;
    //     // cout << m.first.first << " " << m.first.second << " " << m.second << "\n";
    //     cout << "NO\n";
    //     return;
    // }
    
    cout << "YES\n";

}