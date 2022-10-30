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
    vector<int> cnt(500);
    int res = 0;
    for (int i = 0; i < 2; ++i) {
        string s; cin >> s;
        for (int j = 0; j < 2; ++j) {
            if (!cnt[s[j]]) ++res;
            ++cnt[s[j]];
        }
    }
    cout << res - 1 << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}