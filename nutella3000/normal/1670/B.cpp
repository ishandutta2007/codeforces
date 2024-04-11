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
 
 
const int inf = 1e15 + 7;
const int N = (1 << 10);

void run() {
    int n, k; string s;
    cin >> n >> s >> k;
    vector<bool> bad(26);
    for (int i = 0; i < k; ++i) {
        char c; cin >> c;
        bad[c - 'a'] = true;
    }
    int res = 0, cnt = -inf, tmp = 0;
    for (int i = n-1; i >= 0; --i) {
        ++cnt;
        chmax(res, cnt);
        if (bad[s[i] - 'a']) cnt = 0, ++tmp;
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