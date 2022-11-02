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
    for (auto &i : a)
        cin >> i;
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    cout << (a.size() != n ? "NO" : "YES") << '\n';
}


signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}