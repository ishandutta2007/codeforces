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
 
 
const int inf = 1e9 + 7;
const int N = 1 << 20;

void run() {
    int n, k; string s;
    cin >> n >> k >> s;
    vector<bool> used(26);
    for (int i = 0; i < n; ++i) {
        int val = s[i] - 'a';
        while (val && !used[val] && k) {
            used[val] = true; --k; --val;
        }
        while (used[val]) --val;
        s[i] = val + 'a';
    }
    cout << s << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}