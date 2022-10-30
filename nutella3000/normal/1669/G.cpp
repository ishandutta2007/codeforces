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
const int N = 500;

void run() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int it = 0; it < 50; ++it) {
        for (int i = n-1; i >= 0; --i) {
            for (int j = 0; j < m; ++j) {
                if (s[i][j] != '*') continue;
                if (i != n-1 && s[i+1][j] == '.') {
                    swap(s[i+1][j], s[i][j]);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i)
        cout << s[i] << endl;
    cout << endl;
}


signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}