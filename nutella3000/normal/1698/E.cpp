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
const int mod = 998244353;

void run() {
    int n, s; cin >> n >> s;
    vector<int> arr(n);
    vector<bool> a(n), b(n, true);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i]; --arr[i];
    }

    bool bad = false;
    for (int i = 0; i < n; ++i) {
        int v; cin >> v; --v;
        if (v == -2)
            a[arr[i]] = true;
        else {
            b[v] = false;
            if (arr[i] - v > s) bad = true;
        }
    }
    int res = 1;
    for (int i = n-1, it = n-1, cnt = 0; i >= 0; --i) {
        while (it >= 0 && it >= i - s) cnt += b[it--];
        if (a[i]) res = res * cnt-- % mod;
    }
    cout << (bad ? 0ll : res) << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}