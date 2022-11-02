#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const ll inf = 1e9;
const ll mod = 998244353;

void run() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(k);
    for (auto& i : a)
        cin >> i;

    set<int> b;
    for (int i = 0, num = k; i < k; ++i) {
        b.insert(a[i]);
        if (b.size() > n*m - 3) {
            cout << "TIDAK\n";
            return;
        }
        while (b.count(num)) {
            b.erase(num--);
        }
    }
    cout << "YA\n";
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}