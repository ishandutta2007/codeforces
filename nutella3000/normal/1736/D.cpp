#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const ll inf = 1e18;
const ll mod = 998244353;

void run() {
    int n; string s;
    cin >> n >> s;
    vector<int> res{2*n-1};
    for (int i = 0; i < 2*n - 2; i += 2) {
        if (s[i] == s[i+1]) continue;
        res.push_back(i + (s[i] == s[res.back()]));
    }
    if (s[res.back()] != s[2*n-2]) {
        cout << -1 << '\n';
        return;
    }
    
    sort(all(res));
    cout << size(res) << ' ';
    for (auto i : res)
        cout << i+1 << ' ';
    cout << '\n';
    for (int i = 1; i <= 2*n; i += 2)
        cout << i << ' ';
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