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
    vector<int> a(n), b(n);
    for (auto& i : a)
        cin >> i;
    for (auto& i : b)
        cin >> i;

    auto sign = [](int v) { return v < 0 ? -1 : (bool)v; };

    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i] || (b[(i+1) % n] < b[i]-1 && a[i] != b[i])) {
            cout << "NO" << '\n';
            return;
        }
    }


    cout << "YES" << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}