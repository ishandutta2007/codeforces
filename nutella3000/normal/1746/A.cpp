#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const ll inf = 1e15 + 7;
const ll mod = 1e9 + 7;
const int N = 1e6 + 5;

void run() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    bool v = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) v = true;
    }
    cout << (v ? "YES" : "NO") << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}