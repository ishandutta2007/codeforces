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
const int N = (1 << 17);
const int mod = 998244353;

int n = 3;

vvi mult(vvi a, vvi b) {
    vvi c(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int r = 0;
            for (int k = 0; k < n; ++k) {
                r += a[i][k] * b[k][j];
            }
            c[i][j] = r;
        }
    }
    return c;
}

vvi pw(vvi a, int b) {
    vvi res(n, vi(n));
    for (int i = 0; i < n; ++i)
        res[i][i] = 1;
    for (int i = 0; i < b; ++i) {
        res = mult(res, a);
    }
    return res;
}

void print(vvi a) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << a[i][j] << " ";
        cout << '\n';
    }
}

vvi scan() {
    vvi a(n, vi(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    return a;
}

void run() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), pref(n+1);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));
    
    for (int i = 0; i < n; ++i)
        pref[i+1] = pref[i] + a[i];

    for (int i = 0; i < q; ++i) {
        int x, y; cin >> x >> y;
        cout << pref[n-(x-y)] - pref[n-x] << '\n';
    }
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}