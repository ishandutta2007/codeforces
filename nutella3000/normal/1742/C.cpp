#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

void run() {
    int n = 8;
    bool R = false;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        auto it = s.find_first_not_of('R');
        if (it >= s.size()) R = true;
    }
    cout << (R ? "R" : "B") << '\n';
}


signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}