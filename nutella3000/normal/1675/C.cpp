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
    string s; cin >> s;
    int n = siz(s);
    vector<int> one(n+1, 1), zero(n+1, 1);
    for (int i = 0; i < n; ++i)
        one[i+1] = (one[i] & (s[i] != '0'));

    for (int i = n-1; i >= 0; --i)
        zero[i] = (zero[i+1] & (s[i] != '1'));

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (one[i] && zero[i+1]) ++cnt;
    }
    cout << cnt << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}