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
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < m; ++i) {
        int v; cin >> v; ++a[v - 1];
    }

    int l = -1, r = 2*m + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int work = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] < mid) work += (mid - a[i])/2;
            else work -= (a[i] - mid);
        }
        if (work >= 0) r = mid;
        else l = mid;
    }
    cout << r << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}