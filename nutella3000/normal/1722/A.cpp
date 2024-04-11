#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9 + 7;

void run() {
    string s = "Timur";
    int n; cin >> n;
    string t; cin >> t;
    vector<int> cnt(500);
    for (auto i : s)
        ++cnt[i];
    for (auto i : t) {
        if (!cnt[i]) {
            cout << "NO" << '\n';
            return;
        }
        --cnt[i]; 
    }
    cout << (size(t) == size(s) ? "YES" : "NO") << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}