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
    int n;
    cin >> n;
    vector<int> a;
    bool zer = false;
    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        if (v != 0 || !zer) {
            a.eb(v);
            if (v == 0) zer = true;
        }
    }
    if (siz(a) > 8) cout << "NO" << '\n';
    else {
        for (int i = 0; i < siz(a); ++i) {
            for (int j = i+1; j < siz(a); ++j) {
                for (int k = j+1; k < siz(a); ++k) {
                    bool hav = false;
                    for (int q = 0; q < siz(a); ++q) {
                        if (a[q] == a[i] + a[j] + a[k]) hav = true;
                    }
                    if (!hav) {
                        cout << "NO" << '\n';
                        return;
                    }
                }
            }
        }
        cout << "YES" << '\n';
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