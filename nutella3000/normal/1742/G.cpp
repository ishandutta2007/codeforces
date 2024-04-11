#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }


void run() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& i : a)
        cin >> i;

    vector<int> b(n);
    vector<bool> used(n);

    int OR = 0;
    for (int it = 0; it < min(n, 30); ++it) {
        int mx = -1;
        for (int i = 0; i < n; ++i) {
            if (!used[i] && (mx == -1 || (a[i] & ~OR) > (a[mx] & ~OR))) {
                mx = i;
            }
        }
        b[it] = a[mx];
        used[mx] = true;
        OR |= a[mx];
    }
    for (int i = 0, it = 30; i < n; ++i) {
        if (!used[i])
            b[it++] = a[i];
    }
    for (auto i : b)
        cout << i << ' ';
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