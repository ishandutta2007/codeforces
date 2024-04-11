#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9 + 7;
const ll infL = 1e18 + 7;

void run() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int& i : a)
        cin >> i;
    for (int& i : b)
        cin >> i;

    int res = 0;
    for (int bit = 30; bit >= 0; --bit) {
        map<int, int> cnt[2];
        for (int i = 0; i < n; ++i) {
            ++cnt[a[i] >> bit & 1][a[i] & res];
            --cnt[~b[i] >> bit & 1][~b[i] & res];
        }
        bool bad = false;
        for (int i = 0; i < 2; ++i)
            for (auto j : cnt[i])
                bad |= j.second;
        if (!bad) res += (1 << bit);
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