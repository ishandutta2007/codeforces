#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9;
const ll mod = 998244353;

void run() {
    string s, t; cin >> s >> t;

    map<char, int> c{{'S', 1}, {'M', 2}, {'L', 3}};
    if (c[s.back()] != c[t.back()]) {
        cout << (c[s.back()] < c[t.back()] ? "<" : ">") << '\n';
        return;
    }
    if (s.size() == t.size()) {
        cout << "=\n";
    } else if ((s.size() < t.size()) ^ (c[s.back()] == 1)) {
        cout << "<\n";
    } else {
        cout << ">\n";
    }
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}