#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9 + 7;

void run() {
    int n; cin >> n;
    vector<int> up;
    ll sum = 0;

    auto f = [&](int i, char c) {
        if (c == 'L') return i;
        return n - i -1;
    };
    for (int i = 0; i < n; ++i) {
        char c; cin >> c;
        sum += f(i, c);
        up.emplace_back(f(i, c == 'L' ? 'R' : 'L') - f(i, c));
    }
    sort(all(up), [](int v1, int v2) { return v1 > v2; });

    for (int k = 1; k <= n; ++k) {
        if (size(up) > k-1 && up[k-1] >= 0) sum += up[k-1];
        cout << sum << " ";
    }
    cout << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}