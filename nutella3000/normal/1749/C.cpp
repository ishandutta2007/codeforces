#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const ll inf = 1e15;

void run() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& i : a)
        cin >> i;
    sort(all(a));

    for (int k = n; k >= 0; --k) {
        for (int it = 0, id = n-1; it < k; ++it) {
            while (id >= it && a[id] > k - it) --id;
            if (id < it) break;
            --id;
            if (it == k-1) {
                cout << k << '\n';
                return;
            }
        }
    }
    cout << 0 << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}