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
const int mod = 1e9 + 7;

void run() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> pl(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pl[a[i]] = i;
    }
    if (n == 1) {
        cout << 1 << '\n'; return;
    }
    int bl = min(pl[0], pl[1]), br = max(pl[0], pl[1]);
    int cnt = br - bl - 1;
    int res = 1;
    for (int i = 2; i < n; ++i) {
        if (pl[i] > bl && pl[i] < br)
            res = res * cnt-- % mod;
        else if (pl[i] < bl)
            cnt += bl-pl[i]-1, bl = pl[i];
        else
            cnt += pl[i] - br - 1, br = pl[i];
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