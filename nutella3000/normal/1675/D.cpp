#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(a) a.begin(), a.end()
#define siz(a) (int)a.size()
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }
 
 
const int inf = 1e9 + 7;
const int N = 1 << 20;

void run() {
    int n; cin >> n;
    vector<int> p(n), ch(n), used(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i]; --p[i];
        if (p[i] != i) ++ch[p[i]];
    }

    vector<vector<int>> res; 
    for (int st = 0; st < n; ++st) {
        if (ch[st] || used[st]) continue;
        int v = st;
        res.eb();
        while (!used[v]) {
            res.back().eb(v);
            used[v] = true;
            v = p[v];
        }
    }
    cout << siz(res) << '\n';
    for (auto i : res) {
        cout << siz(i) << '\n';
        reverse(all(i));
        for (auto j : i)
            cout << j+1 << " ";
        cout << '\n';
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