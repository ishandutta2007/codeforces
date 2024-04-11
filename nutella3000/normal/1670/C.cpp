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
 
 
const int inf = 1e15 + 7;
const int N = (1 << 10), mod = 1e9 + 7;

void run() {
    int n; cin >> n;
    vector<int> a(n), b(n), d(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; --a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i]; --b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> d[i]; --d[i];
    }

    vector<int> ida(n);
    for (int i = 0; i < n; ++i)
        ida[a[i]] = i;
    
    int res = 1;
    vector<int> used(n);

    for (int st = 0; st < n; ++st) {
        if (used[st] || a[st] == b[st]) continue;
        int v = st; bool was = false;
        while (!used[v]) {
            used[v] = true;
            if (d[v] != -1) was = true;
            v = ida[b[v]];
        }
        if (!was) res = res * 2 % mod;
    }
    cout << res << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}