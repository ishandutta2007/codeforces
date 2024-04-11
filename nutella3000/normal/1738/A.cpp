#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9 + 7;

void run() {
    int n;
    cin >> n;
    vector a(2, vector<int>());
    vector<int> t(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    for (auto& i : b)
        cin >> i;
    for (int i = 0; i < n; ++i) {
        a[t[i]].push_back(b[i]);
    }
    sort(all(a[0]));
    sort(all(a[1]));
    if (a[1].size() < a[0].size()) swap(a[0], a[1]);

    ll sum = accumulate(all(a[0]), 0ll) + accumulate(all(a[1]), 0ll);
    for (int i = 0; i < min(a[0].size(), a[1].size()); ++i) {
        sum += a[0].end()[-i-1];
        sum += a[1].end()[-i-1];
    }
    if (a[0].size() < a[1].size()) {
    } else {
        sum -= min(a[0][0], a[1][0]);
    }
    cout << sum << '\n';
}


signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}