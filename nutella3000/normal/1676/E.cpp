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
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a), [](int v1, int v2) { return v1 > v2; });
    for (int i = 1; i < n; ++i)
        a[i] += a[i-1];

    for (int it = 0; it < q; ++it) {
        int x; cin >> x;
        int l = -1, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (a[mid] >= x) r = mid;
            else l = mid;
        }
        cout << (r == n ? -1 : r + 1) << '\n';
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