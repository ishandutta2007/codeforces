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
    set<string> a, b, c;
    for (int i = 0; i < 3*n; ++i) {
        string s; cin >> s;
        if (i < n) a.emplace(s);
        else if (i < 2*n) b.emplace(s);
        else c.emplace(s);
    }
    auto f = [](int k) {
        if (k == 0) return 3;
        return 2 - k;
    };
    vector<int> res(3);
    for (auto s : a)
        res[0] += f(b.count(s) + c.count(s));
    for (auto s : b)
        res[1] += f(a.count(s) + c.count(s));
    for (auto s : c)
        res[2] += f(b.count(s) + a.count(s));
    cout << res[0] << " " << res[1] << " " << res[2] << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}