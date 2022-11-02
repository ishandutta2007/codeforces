#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9 + 7;
const int N = 2e5 + 3;

void run() {
    int n; cin >> n;
    vector<int> d(n), a(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        a[i] = d[i];
        if (i) {
            a[i] += a[i-1];
        }
    }
    int mn = a[n-1];
    for (int i = n-1; i >= 0; --i) {
        chmin(mn, a[i]);
        if (d[i] && mn - 2 * d[i] >= 0) {
            cout << -1 << '\n';
            return;
        } 
    }
    for (int i : a)
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