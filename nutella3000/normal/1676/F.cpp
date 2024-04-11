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
const int N = 1 << 20, mod = 1e9 + 7;

void run() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));
    a.eb(inf);

    int bl = -1, br = -2;
    int l = -1, r = -2;

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        ++cnt;
        if (a[i+1] != a[i]) {
            if (cnt < k) l = -1, r = -2;
            else {
                if (l == -1) l = a[i];
                r = a[i];
            }
            if (r - l > br - bl) {
                bl = l;
                br = r;
            }
            if (a[i+1] != a[i] + 1) {
                l = -1, r = -2;
            }
            cnt = 0;
        }
    }

    if (bl == -1) cout << -1 << '\n';
    else cout << bl << " " << br << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}