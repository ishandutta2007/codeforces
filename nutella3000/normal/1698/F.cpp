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

vector<pii> res;

void rev(vector<int>& a, int l, int r) {
    vector<int> b;
    for (int i = r; i >= l; --i)
        b.eb(a[i]);
    for (int i = l; i <= r; ++i)
        a[i] = b[i-l];

    res.eb(l+1, r+1);
}

void run() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    vector<vector<int>> gr(n+1, vector<int>(n+1));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i) ++gr[a[i]][a[i-1]], ++gr[a[i-1]][a[i]];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (i) --gr[b[i]][b[i-1]], --gr[b[i-1]][b[i]];
    }
    int cnt = 0;
    for (int i = 0; i <= n; ++i)
        cnt += count_if(all(gr[i]), [](int v) { return (bool)v; });

    if (a[0] != b[0] || cnt) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    for (int i = 1; i < n; ++i) {
        // b[i-1] b[i]
        int mid = -1;
        for (int j = i+1; j < n; ++j)
            if (a[j-1] == b[i-1] && a[j] == b[i]) mid = j;

        if (mid != -1) {
            for (int l = i-1; l < mid; ++l) {
                for (int r = mid; r < n; ++r) {
                    if (a[l] == a[r]) {
                        rev(a, l, r);
                        goto cum;
                    }
                }
            }
            cum:;
        }

        for (int j = i; j < n; ++j) {
            if (a[j-1] == b[i] && a[j] == b[i-1]) {
                rev(a, i-1, j);
                break;
            }
        }
    }
    cout << siz(res) << '\n';
    for (auto i : res)
        cout << i.fi << " " << i.se << '\n';
    res.clear();
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}