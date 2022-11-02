#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }


void run() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& i : a)
        cin >> i;
    vector<array<int, 2>> res;

    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            res.push_back({i, i});
            continue;
        }
        
        int j = i+1;
        while (j < n && a[j] == 0) ++j;
        if (j == n) {
            cout << -1 << '\n';
            return;
        }
        if (a[i] != a[j]) {
            res.push_back({i, j-1});
            res.push_back({j, j});
        } else {
            if (i + 1 != j) res.push_back({i, j-2});
            res.push_back({j-1, j});
        }
        i = j;
    }
    cout << res.size() << '\n';
    for (auto i : res)
        cout << i[0] + 1 << " " << i[1] + 1 << '\n';
}


signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}