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

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>

template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }
 
 
const int inf = 1e9 + 7;

void run() {
    int n; cin >> n;
    vector<int> a;
    vector<bool> used(n+1, false);
    for (int i = 1; i <= n; ++i) {
        int v = i;
        while (v <= n && !used[v] && v <= n) {
            a.eb(v);
            used[v] = true;
            v = 2*v;
        }
    }

    cout << 2 << '\n';
    for (auto i : a)
        cout << i << " ";
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