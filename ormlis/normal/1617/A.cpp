#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
#define vec vector

using namespace std;

using ll = long long;
using ld = double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

void solve() {
    vector<string> a(4);
    string t;
    string s;
    cin >> s >> t;
    for(auto &c : s) {
        int x = 0;
        while(x < 3 && t[x] != c) x++;
        a[x] += c;
    }
    rep(i, 4) sort(all(a[i]));
    vector<int> g(4);
    iota(all(g), 0);
    string res;
    do {
        string f;
        int cur = 0;
        for(auto &i : g) {
            if (i == cur) cur++;
            f += a[i];
        }
        if (cur >= 3) continue;
        if (res.empty()) {
            res = f;
        } else if (res > f){
            res = f;
        }
    } while(next_permutation(all(g)));
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    rep(_, t) {
        solve();
    }
    return 0;
}